#include "geckonetworkmanager.h"
#include <QDebug>
#include <QNetworkReply>
#include <QUrlQuery>

constexpr const char* geckoApiKey = "CG-T1xp7PtrAKvWJd8L5PEY74WD";

GeckoNetworkManager::GeckoNetworkManager(QObject *parent)
    : QObject(parent) {
    m_networkManger = std::make_shared<QNetworkAccessManager>(this);
    connect(m_networkManger.get(), &QNetworkAccessManager::finished, this, &GeckoNetworkManager::replyFinished);
}

void GeckoNetworkManager::getCoinData() {
    QUrl url("https://api.coingecko.com/api/v3/coins/markets");
    QUrlQuery query;

    query.addQueryItem("vs_currency", "usd");

    url.setQuery(query.query());
    QNetworkRequest request(url);

    QSslConfiguration sslConfiguration = request.sslConfiguration();

    sslConfiguration.setProtocol(QSsl::TlsV1_2);
    request.setSslConfiguration(sslConfiguration);
    request.setRawHeader("x_cg_demo_api_key", geckoApiKey);

    m_networkManger->get(request);
}

void GeckoNetworkManager::replyFinished(QNetworkReply *reply) {

    qDebug("REPLY RECEIVED");
    qDebug("network error: ");
    qDebug() << reply->error(); // static_cast<int>(reply->error());
    qDebug() << "emit newDataReceived";

    if (reply->error() == QNetworkReply::NoError) {
        emit newDataReceived(reply->readAll());
    }
    emit errorMessageReceived(static_cast<int>(reply->error()), reply->errorString());
}
