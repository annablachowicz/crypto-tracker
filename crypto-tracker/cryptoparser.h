#pragma once

#include <QObject>
#include "cryptomodel/cryptodata.h"

constexpr const char* currency = "USD";

class CryptoParser : public QObject {
    Q_OBJECT
public:
    CryptoParser(QObject *parent = nullptr);

public slots:
    void parseReply(QByteArray newData);
signals:
    void dataRead(const CryptoData data);
};
