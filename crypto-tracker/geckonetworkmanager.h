#pragma once
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QObject>

class GeckoNetworkManager : public QObject {
    Q_OBJECT

public:
    GeckoNetworkManager(QObject *parent = nullptr);
    void getCoinData();
private:
        QNetworkAccessManager m_networkManger;
private slots:
    void replyFinished(QNetworkReply *reply);

signals:
    void newDataReceived(QByteArray newData);
    void errorMessageReceived(int errorCode, QString errorMessage);
};
