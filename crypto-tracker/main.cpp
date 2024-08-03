#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "cryptocontroller.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    CryptoController controller;

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    qRegisterMetaType<CryptoData>();

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("cryptoController", &controller);
    context->setContextProperty("cryptoModel", controller.cryptoModel());
    qmlRegisterUncreatableMetaObject(CryptoColumnIndices::staticMetaObject, "CryptoColumnIndices", 1, 0, "CryptoColumnIndices", "Error: only enums");

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
