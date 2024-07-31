#include <QNetworkAccessManager>
#include <QObject>

class GeckoNetworkManager : public QObject {
    Q_OBJECT

public:
    GeckoNetworkManager(QObject *parent = nullptr);
    void getCoinData();

private:
    std::shared_ptr<QNetworkAccessManager> m_networkManger;


private slots:
    void replyFinished(QNetworkReply *reply);

};
