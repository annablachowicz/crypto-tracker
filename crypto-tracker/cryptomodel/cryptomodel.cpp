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
        cryptoData.image = value.toString();
        emit dataChanged(index, index);
        return true;
    case TickerRole:
        cryptoData.ticker = value.toString();
        emit dataChanged(index, index);
        return true;
    case CurrencyRole:
        cryptoData.currency = value.toString();
        emit dataChanged(index, index);
        return true;
    case PriceRole:
        cryptoData.price = value.toFloat();
        emit dataChanged(index, index);
        return true;
    case PriceChangePercentage24hRole:
        cryptoData.priceChangePercentage24h = value.toFloat();
        emit dataChanged(index, index);
        return true;
    case PriceChangePercentage1hRole:
        cryptoData.priceChangePercentage1h = value.toFloat();
        emit dataChanged(index, index);
        return true;
    case RankRole:
        cryptoData.rank = value.toFloat();
        emit dataChanged(index, index);
        return true;
    case LastUpdateRole:
        cryptoData.lastUpdate = value.toDateTime();
        emit dataChanged(index, index);
        return true;
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
