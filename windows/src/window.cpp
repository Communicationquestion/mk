#pragma once
#include<basewindows/basewindows.h>
#include <QQmlContext>
#include <basewindows/abmodel.h>
#include<PasswordManagement/PasswordManagement.h>
#include <qstring>
#include <windows.h>

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
	
	wchar_t buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);

	QString s = QString::fromWCharArray(buffer);
	
	engine.load(s.remove(s.length() - 6, 6).replace("\\","/") + "\\windows\\src\\qmls\\Interactive.qml");

	return app.exec();
}

