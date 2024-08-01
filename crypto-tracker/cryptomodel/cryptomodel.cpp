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
    default:
        return {};
    }
}

void CryptoModel::sort(int column, Qt::SortOrder order) {
    if (m_sortColumn != column) {
        m_sortColumn = column;
    }

    beginInsertRows(QModelIndex(), 0, m_cryptoDatas.size()-1);

    switch (column) {
    case CryptoColumnIndices::NameColumn:
        std::sort(m_cryptoDatas.begin(), m_cryptoDatas.end(), [](const CryptoData& c1, const CryptoData& c2) {
            return (c1.name < c2.name);
        });
        break;
    case CryptoColumnIndices::PriceColumn:
        std::sort(m_cryptoDatas.begin(), m_cryptoDatas.end(), [](const CryptoData& c1, const CryptoData& c2) {
            return (c1.price < c2.price);
        });
        break;
    case CryptoColumnIndices::PriceChangePercentage24hColumn:
        std::sort(m_cryptoDatas.begin(), m_cryptoDatas.end(), [](const CryptoData& c1, const CryptoData& c2) {
            return (c1.priceChangePercentage24h < c2.priceChangePercentage24h);
        });
        break;
    default:
        std::sort(m_cryptoDatas.begin(), m_cryptoDatas.end(), [](const CryptoData& c1, const CryptoData& c2) {
            return (c1.rank < c2.rank);
        });
        break;
    }

    endInsertRows();
}

void CryptoModel::defaultSort() {
    sort(m_sortColumn);
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

    return roles;
}
