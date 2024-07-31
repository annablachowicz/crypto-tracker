#include "cryptocontroller.h"

CryptoController::CryptoController(QObject *parent)
    : QObject(parent) {
    connect(&m_networkManager, &GeckoNetworkManager::newDataReceived, &m_parser, &CryptoParser::parseReply);
    connect(&m_parser, &CryptoParser::dataRead, &m_model, &CryptoModel::add);

    m_networkManager.getCoinData();

}
