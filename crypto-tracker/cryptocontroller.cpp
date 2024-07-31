#include "cryptocontroller.h"

CryptoController::CryptoController(QObject *parent)
    : QObject(parent),
    m_model(std::make_shared<CryptoModel>(this)) {
    connect(&m_networkManager, &GeckoNetworkManager::newDataReceived, &m_parser, &CryptoParser::parseReply);
    connect(&m_parser, &CryptoParser::dataRead, m_model.get(), &CryptoModel::add);

    m_networkManager.getCoinData();
}

CryptoModel *CryptoController::cryptoModel() {
    return m_model.get();
}
