#pragma once

#include <QObject>
#include "cryptoparser.h"
#include "cryptomodel/cryptomodel.h"
#include "geckonetworkmanager.h"

class CryptoController : public QObject {
    Q_OBJECT
public:
    CryptoController(QObject *parent = nullptr);

private:
    CryptoParser m_parser;
    CryptoModel m_model;
    GeckoNetworkManager m_networkManager;
};
