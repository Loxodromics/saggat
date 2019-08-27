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
#include <QSurface>
#include "src/common/values.h"
#include "src/common/qmlvalues.h"
#include "src/generation/generator.h"
#include "src/graphics/planetsurfacematerial.h"
#include "src/graphics/moonsurfacematerial.h"
#include "src/graphics/geospheremesh.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QSurfaceFormat defaultFormat;
	defaultFormat.setProfile(QSurfaceFormat::CoreProfile);
	defaultFormat.setVersion(3, 2);
	defaultFormat.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
	QSurfaceFormat::setDefaultFormat(defaultFormat);

	qmlRegisterType<Saggat::PlanetSurfaceMaterial>("Saggat", 1, 0, "PlanetSurfaceMaterial");
	qmlRegisterType<Saggat::MoonSurfaceMaterial>("Saggat", 1, 0, "MoonSurfaceMaterial");
	qmlRegisterType<Saggat::QmlValues>("Saggat", 1, 0, "QmlValues");
	qmlRegisterType<GeosphereMesh>("LFD", 1, 0, "GeosphereMesh");

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
