#include<basewindows/basewindows.h>
#include<PasswordManagement/PasswordManagement.h>
#include <QQmlContext>
int initqmlapp(int argc, char* argv[]) {
    
    QGuiApplication app(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    qmlRegisterType<Qmlmod::Passwd>("passwd", 1, 0, "PassWd");
    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
    &app, []() { QCoreApplication::exit(-1); },
    Qt::QueuedConnection);
    
    engine.load(".\\windows\\src\\qmls\\Interactive.qml");

    return app.exec();
}

