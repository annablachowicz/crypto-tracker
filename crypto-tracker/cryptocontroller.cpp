#include <QtConcurrent>
#include "cryptocontroller.h"

CryptoController::CryptoController(QObject *parent)
    : QObject(parent),
    m_model(std::make_shared<CryptoModel>(this)) {
    connect(&m_networkManager, &GeckoNetworkManager::newDataReceived, this, &CryptoController::onNewDataReceived);
    connect(&m_networkManager, &GeckoNetworkManager::errorMessageReceived, this, &CryptoController::errorMessageReceived);
    connect(&m_networkManager, &GeckoNetworkManager::errorMessageReceived, this, &CryptoController::onErrorMessageReceived);
    connect(&m_parser, &CryptoParser::dataRead, m_model.get(), &CryptoModel::addOrUpdate);
    connect(&m_parser, &CryptoParser::dataRead, this, &CryptoController::updateFinished);
    connect(&m_timer, &QTimer::timeout, this, &CryptoController::timerElapsed);

    m_networkManager.getCoinData();
    m_timer.start(3000);
}

CryptoModel *CryptoController::cryptoModel() {
    return m_model.get();
}

bool CryptoController::isStaleData() {
    return m_isStaleData;
}

void CryptoController::parseConcurrentRun(QByteArray newData) {
    QtConcurrent::run(&m_parser, &CryptoParser::parseReply, newData);
}

void CryptoController::onNewDataReceived(QByteArray newData) {
    parseConcurrentRun(newData);
}

void CryptoController::onErrorMessageReceived(int errorCode) {
    if (errorCode != 0) {
        if (!m_isStaleData) {
            m_isStaleData = true;
            emit isStaleDataChanged();
        }
        emit updateFinished();
    } else {
        if (m_isStaleData) {
            m_isStaleData = false;
            emit isStaleDataChanged();
        }
    }
}

void CryptoController::timerElapsed() {
    m_networkManager.getCoinData();
    emit updateStarted();
}
