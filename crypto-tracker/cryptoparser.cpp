#include "cryptoparser.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

CryptoParser::CryptoParser(QObject *parent)
    : QObject(parent) {}

void CryptoParser::parseReply(QByteArray newData) {
    try {
        QJsonDocument document = QJsonDocument::fromJson(newData);
        QJsonArray array = document.array();
        foreach (const QJsonValue &value, array) {
            CryptoData cryptoData(value["name"].toString(),
                                  value["image"].toString(),
                                  value["symbol"].toString(),
                                  currency,
                                  value["current_price"].toDouble(),
                                  value["price_change_percentage_24h"].toDouble(),
                                  value["price_change_percentage_1h"].toDouble(),
                                  value["market_cap_rank"].toInt(),
                                  value["last_updated"].toVariant().toDateTime());
            emit dataRead(cryptoData);
        }
    } catch (std::exception &e) {
        emit dataReadFailed(typeid(e).name());
    }
}
