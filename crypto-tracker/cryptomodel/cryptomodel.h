#pragma once
#include <QObject>
#include <QAbstractListModel>

#include "cryptodata.h"

//todo wywalić to i używać CryptoRoles
namespace CryptoColumnIndices {
Q_NAMESPACE
enum CryptoColumnIndices {
    NameColumn,
    ImageColumn,
    TickerColumn,
    CurrencyColumn,
    PriceColumn,
    PriceChangePercentage24hColumn,
    PriceChangePercentage1hColumn,
    RankColumn
};
Q_ENUMS(CryptoColumnIndices)
}

class CryptoModel : public QAbstractListModel {
    Q_OBJECT

public:
    enum CryptoRoles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        ImageRole,
        TickerRole,
        CurrencyRole,
        PriceRole,
        PriceChangePercentage24hRole,
        PriceChangePercentage1hRole,
        RankRole
    };

    CryptoModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Q_INVOKABLE void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
    void add(const CryptoData cryptoData);
    void reset();

public slots:
    void addOrUpdate(const CryptoData &value);

protected:
    QHash<int, QByteArray> roleNames() const override;
    QList<CryptoData> m_cryptoDatas;
};
