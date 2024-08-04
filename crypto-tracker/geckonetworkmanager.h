#pragma once
#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>

class GeckoNetworkManager : public QObject {
    Q_OBJECT

public:
    GeckoNetworkManager(QObject *parent = nullptr);

private:
    QNetworkAccessManager m_networkManger;

public slots:
    void getCoinData();

private slots:
    void replyFinished(QNetworkReply *reply);

signals:
    void newDataReceived(QByteArray newData);
    void errorMessageReceived(int errorCode, QString errorMessage);
};
