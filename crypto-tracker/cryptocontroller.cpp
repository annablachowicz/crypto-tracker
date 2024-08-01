#include <QtConcurrent>
#include "cryptocontroller.h"

CryptoController::CryptoController(QObject *parent)
    : QObject(parent),
    m_model(std::make_shared<CryptoModel>(this)) {
    connect(&m_networkManager, &GeckoNetworkManager::newDataReceived, this, &CryptoController::onNewDataReceived);
    connect(&m_networkManager, &GeckoNetworkManager::errorMessageReceived, this, &CryptoController::errorMessageReceived);
    connect(&m_networkManager, &GeckoNetworkManager::errorMessageReceived, this, &CryptoController::onErrorMessageReceived);
    connect(&m_parser, &CryptoParser::dataRead, m_model.get(), &CryptoModel::add);
    connect(&m_parser, &CryptoParser::parsingFinished, this, &CryptoController::onParsingFinished);
    connect(&m_timer, &QTimer::timeout, &m_networkManager, &GeckoNetworkManager::getCoinData);

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
    m_model->reset();
    parseConcurrentRun(newData);
}

void CryptoController::onErrorMessageReceived(int errorCode, QString errorMessage) {
    if (errorCode != 0) {
        if (!m_isStaleData) {
            m_isStaleData = true;
            emit isStaleDataChanged();
        }
    } else {
        if (m_isStaleData) {
            m_isStaleData = false;
            emit isStaleDataChanged();
        }
    }
}

void CryptoController::onParsingFinished() {
    m_model->defaultSort();
}
