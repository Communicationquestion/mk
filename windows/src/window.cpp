#include<basewindows/basewindows.h>
int initqmlapp(int argc, char* argv[]) {

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load("D:\\projects\\vs\\mk\\windows\\src\\qmls\\Interactive.qml");

    return app.exec();
}


namespace BaseWindow {





}