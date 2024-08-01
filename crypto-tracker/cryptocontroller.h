#pragma once

#include <QObject>
#include <QTimer>
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
    QTimer m_timer;

private slots:
    void parseConcurrentRun(QByteArray newData);

signals:
    void errorMessageReceived(int errorCode, QString errorMessage);
};
