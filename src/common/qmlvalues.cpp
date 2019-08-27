//
//  qmlvalues.cpp
//  Saggat
//
//  Created by philipp on 26.08.2019.
//  Copyright (c) 2019 Philipp Engelhard. All rights reserved.
//
#include "qmlvalues.h"

namespace Saggat {

QmlValues::QmlValues()
{
	QObject::connect(&Values::getInstance(), &Values::displayHeightChanged,
					 this, &QmlValues::setTerrainDisplayHeight);
	QObject::connect(&Values::getInstance(), &Values::terrainSeaLevelFactorChanged,
					 this, &QmlValues::setTerrainSeaLevelFactor);
	QObject::connect(&Values::getInstance(), &Values::terrainPlanetScaleChanged,
					 this, &QmlValues::setTerrainPlanetScale);

	QObject::connect(&Values::getInstance(), &Values::terrainHeightFactorChanged,
					 this, &QmlValues::setTerrainHeightFactor);
	QObject::connect(&Values::getInstance(), &Values::terrainE0Changed,
					 this, &QmlValues::setTerrainE0);
	QObject::connect(&Values::getInstance(), &Values::terrainE1Changed,
					 this, &QmlValues::setTerrainE1);
	QObject::connect(&Values::getInstance(), &Values::terrainE2Changed,
					 this, &QmlValues::setTerrainE2);
	QObject::connect(&Values::getInstance(), &Values::terrainColdnessChanged,
					 this, &QmlValues::setTerrainColdness);
	QObject::connect(&Values::getInstance(), &Values::terrainSeedChanged,
					 this, &QmlValues::setTerrainSeed);
}

void QmlValues::setTerrainSeaLevelFactor(qreal terrainSeaLevelFactor)
{
	Values::getInstance().setTerrainSeaLevelFactor( terrainSeaLevelFactor );
	emit terrainSeaLevelFactorChanged(Values::getInstance().terrainSeaLevelFactor());
}

void QmlValues::setTerrainDisplayHeight(bool terrainDisplayHeight)
{
	Values::getInstance().setDisplayHeight(terrainDisplayHeight);
	emit terrainDisplayHeightChanged(Values::getInstance().displayHeight());
}

void QmlValues::setTerrainPlanetScale(qreal terrainPlanetScale)
{
	Values::getInstance().setTerrainPlanetScale(terrainPlanetScale);
	emit terrainPlanetScaleChanged(Values::getInstance().terrainPlanetScale());
}

void QmlValues::setTerrainHeightFactor(qreal terrainHeightFactor)
{
	Values::getInstance().setTerrainHeightFactor(terrainHeightFactor);
	emit terrainHeightFactorChanged(Values::getInstance().terrainHeightFactor());
}

void QmlValues::setTerrainE0(qreal terrainE0)
{
	Values::getInstance().setTerrainE0(terrainE0);
	emit terrainE0Changed(Values::getInstance().terrainE0());
}

void QmlValues::setTerrainE1(qreal terrainE1)
{
	Values::getInstance().setTerrainE1(terrainE1);
	emit terrainE1Changed(Values::getInstance().terrainE1());
}

void QmlValues::setTerrainE2(qreal terrainE2)
{
	Values::getInstance().setTerrainE2(terrainE2);
	emit terrainE2Changed(Values::getInstance().terrainE2());
}

void QmlValues::setTerrainColdness(qreal terrainColdness)
{
	Values::getInstance().setTerrainColdness(terrainColdness);
	emit terrainColdnessChanged(Values::getInstance().terrainColdness());
}

void QmlValues::setTerrainSeed(int terrainSeed)
{
	Values::getInstance().setTerrainSeed(terrainSeed);
	emit terrainSeedChanged(Values::getInstance().terrainSeed());
}

} /// namespace Saggat
