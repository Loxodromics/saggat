//
//  qmlvalues.h
//  Saggat
//
//  Created by philipp on 26.08.2019.
//  Copyright (c) 2019 Philipp Engelhard. All rights reserved.
//
#ifndef QMLVALUES_H
#define QMLVALUES_H

#include "values.h"
#include <QQuickItem>

namespace Saggat {

class QmlValues : public QQuickItem
{
	Q_OBJECT

public:
	QmlValues();

	Q_PROPERTY(qreal terrainSeaLevelFactor READ terrainSeaLevelFactor WRITE setTerrainSeaLevelFactor NOTIFY terrainSeaLevelFactorChanged)
	Q_PROPERTY(bool terrainDisplayHeight READ terrainDisplayHeight WRITE setTerrainDisplayHeight NOTIFY terrainDisplayHeightChanged)
	Q_PROPERTY(qreal terrainPlanetScale READ terrainPlanetScale WRITE setTerrainPlanetScale NOTIFY terrainPlanetScaleChanged)
	Q_PROPERTY(qreal terrainHeightFactor READ terrainHeightFactor WRITE setTerrainHeightFactor NOTIFY terrainHeightFactorChanged)
	Q_PROPERTY(qreal terrainE0 READ terrainE0 WRITE setTerrainE0 NOTIFY terrainE0Changed)
	Q_PROPERTY(qreal terrainE1 READ terrainE1 WRITE setTerrainE1 NOTIFY terrainE1Changed)
	Q_PROPERTY(qreal terrainE2 READ terrainE2 WRITE setTerrainE2 NOTIFY terrainE2Changed)
	Q_PROPERTY(qreal terrainColdness READ terrainColdness WRITE setTerrainColdness NOTIFY terrainColdnessChanged)
	Q_PROPERTY(int terrainSeed READ terrainSeed WRITE setTerrainSeed NOTIFY terrainSeedChanged)

	qreal terrainSeaLevelFactor() const
	{
		return Values::getInstance().terrainSeaLevelFactor();
	}

	bool terrainDisplayHeight() const
	{
		return Values::getInstance().displayHeight();
	}

	qreal terrainPlanetScale() const
	{
		return Values::getInstance().terrainPlanetScale();
	}

	qreal terrainHeightFactor() const
	{
		return Values::getInstance().terrainHeightFactor();
	}

	qreal terrainE0() const
	{
		return Values::getInstance().terrainE0();
	}

	qreal terrainE1() const
	{
		return Values::getInstance().terrainE1();
	}

	qreal terrainE2() const
	{
		return Values::getInstance().terrainE2();
	}

	qreal terrainColdness() const
	{
		return Values::getInstance().terrainColdness();
	}

	int terrainSeed() const
	{
		return Values::getInstance().terrainSeed();
	}

signals:
	void terrainSeaLevelFactorChanged(qreal terrainSeaLevelFactor);
	void terrainDisplayHeightChanged(bool terrainDisplayHeight);
	void terrainPlanetScaleChanged(qreal terrainPlanetScale);
	void terrainHeightFactorChanged(qreal terrainHeightFactor);
	void terrainE0Changed(qreal terrainE0);
	void terrainE1Changed(qreal terrainE1);
	void terrainE2Changed(qreal terrainE2);
	void terrainColdnessChanged(qreal terrainColdness);
	void terrainSeedChanged(int terrainSeed);

public slots:
	void setTerrainSeaLevelFactor(qreal terrainSeaLevelFactor);
	void setTerrainDisplayHeight(bool terrainDisplayHeight);
	void setTerrainPlanetScale(qreal terrainPlanetScale);
	void setTerrainHeightFactor(qreal terrainHeightFactor);
	void setTerrainE0(qreal terrainE0);
	void setTerrainE1(qreal terrainE1);
	void setTerrainE2(qreal terrainE2);
	void setTerrainColdness(qreal terrainColdness);
	void setTerrainSeed(int terrainSeed);
};

} /// namespace Saggat

#endif // QMLVALUES_H
