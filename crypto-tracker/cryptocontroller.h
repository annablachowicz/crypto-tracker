#pragma once

#include <QObject>
#include "cryptoparser.h"
#include "cryptomodel/cryptomodel.h"
#include "geckonetworkmanager.h"

class CryptoController : public QObject {
    Q_OBJECT
public:
    CryptoController(QObject *parent = nullptr);
    CryptoModel* cryptoModel();

private:
    CryptoParser m_parser;
    std::shared_ptr<CryptoModel> m_model;
    GeckoNetworkManager m_networkManager;

signals:
    void errorMessageReceived(int errorCode, QString errorMessage);
};
