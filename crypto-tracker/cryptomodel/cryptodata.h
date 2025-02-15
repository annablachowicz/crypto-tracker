#pragma once
#include <QObject>
#include <QDateTime>

class CryptoData {
public:
    CryptoData(QString _name,
               QString _image,
               QString _ticker,
               QString _currency,
               float _price,
               float _priceChangePercentage24h,
               float _priceChangePercentage1h,
               int _rank,
               QDateTime _lastUpdate)
        : name(std::move(_name)),
        image(std::move(_image)),
        ticker(std::move(_ticker)),
        currency(std::move(_currency)),
        price(std::move(_price)),
        priceChangePercentage24h(std::move(_priceChangePercentage24h)),
        priceChangePercentage1h(std::move(_priceChangePercentage1h)),
        rank(std::move(_rank)),
        lastUpdate(std::move(_lastUpdate)) {}

    CryptoData() {}

    QString name;
    QString image;
    QString ticker;
    QString currency;
    float price;
    float priceChangePercentage24h;
    float priceChangePercentage1h;
    int rank;
    QDateTime lastUpdate;
};
Q_DECLARE_METATYPE(CryptoData);
