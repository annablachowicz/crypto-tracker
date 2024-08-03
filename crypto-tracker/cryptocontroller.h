#pragma once

#include <QObject>
#include <QTimer>
#include "cryptoparser.h"
#include "cryptomodel/cryptomodel.h"
#include "geckonetworkmanager.h"
#include "randomchangesgenerator.h"

class CryptoController : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool isStaleData READ isStaleData NOTIFY isStaleDataChanged)

public:
    CryptoController(QObject *parent = nullptr);
    CryptoModel* cryptoModel();
    Q_INVOKABLE void makeRandomChanges(int startIndex, int endIndex);

    bool isStaleData();

private:
    CryptoParser m_parser;
    std::shared_ptr<CryptoModel> m_model;
    GeckoNetworkManager m_networkManager;
    RandomChangesGenerator m_randomGenerator;

    QTimer m_timer;
    bool m_isStaleData = false;

    void parseConcurrentRun(QByteArray newData);

private slots:
    void onNewDataReceived(QByteArray newData);
    void onErrorMessageReceived(int errorCode);
    void timerElapsed();

signals:
    void errorMessageReceived(int errorCode, QString errorMessage);
    void isStaleDataChanged();
    void updateStarted();
    void updateFinished();
};
