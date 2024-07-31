#include "cryptoparser.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

CryptoParser::CryptoParser(QObject *parent)
    : QObject(parent) {}

void CryptoParser::parseReply(QByteArray newData) {
    QJsonDocument document = QJsonDocument::fromJson(newData);

    QJsonArray array = document.array();
    foreach (const QJsonValue &value, array) {
        CryptoData cryptoData(value["name"].toString(),
                              value["image"].toString(),
                              value["symbol"].toString(),
                              "USD",
                              value["price"].toDouble(),
                              value["price_change_percentage_24h"].toDouble(),
                              value["price_change_percentage_1h"].toDouble());
        emit dataRead(cryptoData);
    }
}
