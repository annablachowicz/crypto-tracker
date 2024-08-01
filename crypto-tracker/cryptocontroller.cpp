#include <QtConcurrent>
#include "cryptocontroller.h"

CryptoController::CryptoController(QObject *parent)
    : QObject(parent),
    m_model(std::make_shared<CryptoModel>(this)) {
    connect(&m_networkManager, &GeckoNetworkManager::newDataReceived, this, &CryptoController::parseConcurrentRun);
    connect(&m_networkManager, &GeckoNetworkManager::errorMessageReceived, this, &CryptoController::errorMessageReceived);
    connect(&m_parser, &CryptoParser::dataRead, m_model.get(), &CryptoModel::add);

    m_networkManager.getCoinData();
}

CryptoModel *CryptoController::cryptoModel() {
    return m_model.get();
}

void CryptoController::parseConcurrentRun(QByteArray newData) {
    QtConcurrent::run(&m_parser, &CryptoParser::parseReply, newData);
}
