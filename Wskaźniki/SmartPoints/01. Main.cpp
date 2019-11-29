#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "smartpointanalizer.h"
#include "smartpointglobalqml.h"

static QObject *smartpoint_global_singleton(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    static SmartPointGlobalQml *singleton = new SmartPointGlobalQml();
    return singleton;
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<SmartPointAnalizer>("SmartPoints", 1, 0, "SmartPointAnalizer");
    qmlRegisterSingletonType<SmartPointGlobalQml>("SmartPoints", 1, 0, "SmartPointGlobal", smartpoint_global_singleton);

    QQmlApplicationEngine qml;
    qml.load( app.applicationDirPath() + "/qml/main.qml" );

    return app.exec();
}
