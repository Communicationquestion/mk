#pragma once
#include <basewindows/basewindows.h>
#include <QQmlContext>
#include <basewindows/abmodel.h>
#include <PasswordManagement/PasswordManagement.h>
#include <qguiapplication.h>
#include <QQmlApplicationEngine>

int initqmlapp(int argc, char* argv[]) {

	QGuiApplication app(argc, argv);
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	//const QUrl url(QStringLiteral("qrc:src/qmls/Interactive.qml"));
	qmlRegisterType<Qmlmod::Passwd>("passwd", 1, 0, "PassWd");
	qmlRegisterType<Qmlmod::TxtTable>("txtTable", 1, 0, "TxtTable");
	qmlRegisterSingletonInstance("MyModel", 1, 0, "MyListModel", MyListModel::getInstance());
	QQmlApplicationEngine engine;
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
		&app, []() { QCoreApplication::exit(-1); },
		Qt::QueuedConnection);

	std::filesystem::path currentPath = std::filesystem::current_path();
	std::string str = currentPath.string();
	QString path(str.c_str());
	engine.load(path + "\\windows\\src\\qmls\\Interactive.qml");
	return app.exec();
}

