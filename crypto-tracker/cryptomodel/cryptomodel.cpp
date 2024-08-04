#include "cryptomodel.h"
#include <QDebug>

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
    case RankRole:
        return cryptoData.rank;
    case LastUpdateRole:
        return cryptoData.lastUpdate;
    default:
        return {};
    }
}

bool CryptoModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    CryptoData &cryptoData = m_cryptoDatas[index.row()];
    switch (role) {
    case ImageRole:
        if (cryptoData.image != value.toString()) {
            cryptoData.image = value.toString();
            emit dataChanged(index, index);
            return true;
        } return false;
    case TickerRole:
        if (cryptoData.ticker != value.toString()) {
            cryptoData.ticker = value.toString();
            emit dataChanged(index, index);
            return true;
        } return false;
    case CurrencyRole:
        if (cryptoData.currency != value.toString()) {
            cryptoData.currency = value.toString();
            emit dataChanged(index, index);
            return true;
        } return false;
    case PriceRole:
        if (cryptoData.price != value.toFloat()) {
            cryptoData.price = value.toFloat();
            emit dataChanged(index, index);
            return true;
        } return false;
    case PriceChangePercentage24hRole:
        if (cryptoData.priceChangePercentage24h != value.toFloat()) {
            cryptoData.priceChangePercentage24h = value.toFloat();
            emit dataChanged(index, index);
            return true;
        } return false;
    case PriceChangePercentage1hRole:
        if (cryptoData.priceChangePercentage1h != value.toFloat()) {
            cryptoData.priceChangePercentage1h = value.toFloat();
            emit dataChanged(index, index);
            return true;
        } return false;
    case RankRole:
        if (cryptoData.rank != value.toFloat()) {
            cryptoData.rank = value.toFloat();
        emit dataChanged(index, index);
        return true;
        } return false;
    case LastUpdateRole:
        if (cryptoData.lastUpdate != value.toDateTime()) {
        cryptoData.lastUpdate = value.toDateTime();
        emit dataChanged(index, index);
        return true;
        } return false;
    default:
        return false;
    }

}

void CryptoModel::sort(int column, Qt::SortOrder order) {
    switch (column) {
    case CryptoColumnIndices::NameColumn:
        std::sort(m_cryptoDatas.begin(), m_cryptoDatas.end(), [order](const CryptoData& c1, const CryptoData& c2) {
            if (order == Qt::AscendingOrder) return (c1.name < c2.name);
            return (c1.name > c2.name);
        });
        break;
    case CryptoColumnIndices::PriceColumn:
        std::sort(m_cryptoDatas.begin(), m_cryptoDatas.end(), [order](const CryptoData& c1, const CryptoData& c2) {
            if (order == Qt::AscendingOrder) return (c1.price < c2.price);
            return (c1.price > c2.price);
        });
        break;
    case CryptoColumnIndices::PriceChangePercentage24hColumn:
        std::sort(m_cryptoDatas.begin(), m_cryptoDatas.end(), [order](const CryptoData& c1, const CryptoData& c2) {
            if (order == Qt::AscendingOrder) return (c1.priceChangePercentage24h < c2.priceChangePercentage24h);
            return (c1.priceChangePercentage24h > c2.priceChangePercentage24h);
        });
        break;
    default:
        std::sort(m_cryptoDatas.begin(), m_cryptoDatas.end(), [order](const CryptoData& c1, const CryptoData& c2) {
            if (order == Qt::AscendingOrder) return (c1.rank < c2.rank);
            return (c1.rank > c2.rank);
        });
        break;
    }

    emit dataChanged(this->index(0), this->index(m_cryptoDatas.count()-1));
}

void CryptoModel::addOrUpdate(const CryptoData &value) {
    // comparing names and not id as coingecko API return 0 for all ids
    auto it = std::find_if(m_cryptoDatas.begin(), m_cryptoDatas.end(), [&](const CryptoData &data) {return data.name == value.name; });

    if (it != m_cryptoDatas.end()) {
        int index = std::distance(m_cryptoDatas.begin(), it);
        emit itemDataUpdateStarted(index);
        setData(this->index(index), value.image, ImageRole);
        setData(this->index(index), value.ticker, TickerRole);
        setData(this->index(index), value.currency, CurrencyRole);
        setData(this->index(index), value.price, PriceRole);
        setData(this->index(index), value.priceChangePercentage24h, PriceChangePercentage24hRole);
        setData(this->index(index), value.priceChangePercentage1h, PriceChangePercentage1hRole);
        setData(this->index(index), value.rank, RankRole);
        setData(this->index(index), value.lastUpdate, LastUpdateRole);
    } else {
        add(value);
    }
}

void CryptoModel::add(const CryptoData cryptoData) {
    beginInsertRows(QModelIndex(), m_cryptoDatas.size(), m_cryptoDatas.size());
    m_cryptoDatas.push_back(cryptoData);
    endInsertRows();
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
    roles[RankRole] = "rank";
    roles[LastUpdateRole] = "lastUpdate";

    return roles;
}

void CryptoModel::onChangePrice(int index, ChangeType changeType) {
    float price = m_cryptoDatas[index].price;
    if (changeType == Increase) {
        setData(this->index(index), 1.02f * price, PriceRole);
    } else {
        setData(this->index(index), 0.98f * price, PriceRole);
    }
}
