//
//  main.cpp
//  Sagget
//
//  Created by philipp on 13.10.2018.
//  Copyright (c) 2018 Philipp Engelhard. All rights reserved.
//
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "src/common/values.h"
#include "src/generation/generator.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;

	engine.rootContext()->setContextProperty( QStringLiteral("Values"),
											  &Saggat::Values::getInstance() );

	engine.rootContext()->setContextProperty( QStringLiteral("Generator"),
											  &Saggat::Generator::getInstance() );

	engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
