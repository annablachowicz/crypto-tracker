#pragma once
#include <QObject>
#include <QAbstractListModel>

#include "cryptodata.h"

class CryptoModel : public QAbstractListModel {
    Q_OBJECT

public:
    enum CryptoRoles {
        NameRole = Qt::UserRole + 1,
        ImageRole,
        TickerRole,
        CurrencyRole,
        PriceRole,
        PriceChangePercentage24hRole,
        PriceChangePercentage1hRole
    };

    explicit CryptoModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    void reset();

public slots:
    void add(const CryptoData cryptoData);

protected:
    QHash<int, QByteArray> roleNames() const override;
    QList<CryptoData> m_cryptoDatas;
};
