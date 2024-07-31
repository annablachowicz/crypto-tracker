#include "cryptomodel.h"
//#include <QDebug>

CryptoModel::CryptoModel(QObject *parent)
    : QAbstractListModel(parent) {}

int CryptoModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_cryptoDatas.count();
}

QVariant CryptoModel::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= m_cryptoDatas.count())
        return {};
    const CryptoData &cryptoData = m_cryptoDatas[index.row()];
    switch (role) {
    case NameRole:
        return cryptoData.name;
    case ImageRole:
        return cryptoData.image;
    case TickerRole:
        return cryptoData.ticker;
    case CurrencyRole:
        return cryptoData.currency;
    case PriceRole:
        return cryptoData.price;
    case PriceChangePercentage24hRole:
        return cryptoData.priceChangePercentage24h;
    case PriceChangePercentage1hRole:
        return cryptoData.priceChangePercentage1h;
    default:
        return {};
    }
}

void CryptoModel::add(const CryptoData cryptoData) {
//    qDebug() << "ADDING CRYPTO DATA TO MODEL";
    m_cryptoDatas.push_back(cryptoData);
}

void CryptoModel::reset() {
    beginResetModel();
    m_cryptoDatas.clear();
    endResetModel();
}

QHash<int, QByteArray> CryptoModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[ImageRole] = "image";
    roles[TickerRole] = "ticker";
    roles[CurrencyRole] = "currency";
    roles[PriceRole] = "price";
    roles[PriceChangePercentage24hRole] = "priceChange24h";
    roles[PriceChangePercentage1hRole] = "priceChange1h";

}
