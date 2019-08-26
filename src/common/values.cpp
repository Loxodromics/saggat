//
//  values.cpp
//  Saggat
//
//  Created by philipp on 16.10.2018.
//  Copyright (c) 2018 Philipp Engelhard. All rights reserved.
//
#include "values.h"

namespace Saggat {

Values::Values(QObject *parent)
	: QObject(parent),
	  m_planetBaseRadius(10.0),
	  m_planetRadiusVariance(3.0),
	  m_planetBaseRotationDuration(40000),
	  m_planetRotationDurationVariance(10000),
	  m_planetMinRotationDuration(1000),
	  m_ringBaseWidth(5.0),
	  m_ringWidthVariance(4.0),
	  m_ringOrbitalDistance(10.0),
	  m_ringOrbitalDistanceVariance(3.0),
	  m_ringDensityFactor(2.0),
	  m_ringBaseColor(QColor()),
	  m_ringBaseRotationTime(8000),
	  m_ringRotationTimeVariance(2000),
	  m_ringAngleVariance(10.0),
	  m_rockBaseSize(0.5),
	  m_rockSizeVariance(0.15),
	  m_rockOrbitalDistanceVariance(2.5),
	  m_rockHeightVariance(0.25),
	  m_rockColorVariance(0.1),
	  m_moonCountVariance(2.0),
	  m_moonBaseSizeFactor(0.1),
	  m_moonSizeVariance(1.0),
	  m_moonOrbitalDistanceVariance(4.0),
	  m_moonCountToPlanetSizeFactor(0.3),
	  m_moonAngleVariance(10.0),
	  m_terrainE0(1.0),
	  m_terrainE1(0.5),
	  m_terrainE2(0.25),
	  m_terrainE3(0.125),
	  m_terrainE4(0.0625),
	  m_terrainExp(1.0),
	  m_terrainHeightFactor(0.2),
	  m_terrainSeed(186),
	  m_terrainPlanetScale(1.0),
	  m_displayHeight(false),
	  m_terrainOctaves(4),
	  m_terrainColdness(1.0),
	  m_terrainSeaLevelFactor(0.1)
{

}

qreal Values::planetBaseRadius() const
{
	return this->m_planetBaseRadius;
}

qreal Values::planetRadiusVariance() const
{
	return this->m_planetRadiusVariance;
}

int Values::planetBaseRotationDuration() const
{
	return this->m_planetBaseRotationDuration;
}

int Values::planetRotationDurationVariance() const
{
	return this->m_planetRotationDurationVariance;
}

int Values::planetMinRotationDuration() const
{
	return this->m_planetMinRotationDuration;
}

qreal Values::ringBaseWidth() const
{
	return this->m_ringBaseWidth;
}

qreal Values::ringWidthVariance() const
{
	return this->m_ringWidthVariance;
}

qreal Values::ringOrbitalDistance() const
{
	return this->m_ringOrbitalDistance;
}

qreal Values::ringOrbitalDistanceVariance() const
{
	return this->m_ringOrbitalDistanceVariance;
}

qreal Values::ringDensityFactor() const
{
	return this->m_ringDensityFactor;
}

QColor Values::ringBaseColor() const
{
	return this->m_ringBaseColor;
}

qreal Values::ringAngleVariance() const
{
	return this->m_ringAngleVariance;
}

void Values::setPlanetBaseRadius(qreal planetBaseRadius)
{

	if ( qFuzzyCompare(this->m_planetBaseRadius, planetBaseRadius) )
		return;

	this->m_planetBaseRadius = planetBaseRadius;
	emit planetBaseRadiusChanged(this->m_planetBaseRadius);
}

void Values::setPlanetRadiusVariance(qreal planetRadiusVariance)
{

	if ( qFuzzyCompare(this->m_planetRadiusVariance, planetRadiusVariance) )
		return;

	this->m_planetRadiusVariance = planetRadiusVariance;
	emit planetRadiusVarianceChanged(this->m_planetRadiusVariance);
}

void Values::setPlanetBaseRotationDuration(int planetBaseRotationDuration)
{
	if ( this->m_planetBaseRotationDuration == planetBaseRotationDuration )
		return;

	this->m_planetBaseRotationDuration = planetBaseRotationDuration;
	emit planetBaseRotationDurationChanged(this->m_planetBaseRotationDuration);
}

void Values::setPlanetRotationDurationVariance(int planetRotationDurationVariance)
{

	if ( this->m_planetRotationDurationVariance == planetRotationDurationVariance )
		return;

	this->m_planetRotationDurationVariance = planetRotationDurationVariance;
	emit planetRotationDurationVarianceChanged(this->m_planetRotationDurationVariance);
}

void Values::setPlanetMinRotationDuration(int planetMinRotationDuration)
{
	if (this->m_planetMinRotationDuration == planetMinRotationDuration)
		return;

	this->m_planetMinRotationDuration = planetMinRotationDuration;
	emit planetMinRotationDurationChanged(this->m_planetMinRotationDuration);
}

void Values::setRingBaseWidth(qreal ringBaseWidth)
{

	if (qFuzzyCompare(this->m_ringBaseWidth, ringBaseWidth))
		return;

	this->m_ringBaseWidth = ringBaseWidth;
	emit ringBaseWidthChanged(this->m_ringBaseWidth);
}

void Values::setRingWidthVariance(qreal ringWidthVariance)
{

	if (qFuzzyCompare(this->m_ringWidthVariance, ringWidthVariance))
		return;

	this->m_ringWidthVariance = ringWidthVariance;
	emit ringWidthVarianceChanged(this->m_ringWidthVariance);
}

void Values::setRingOrbitalDistance(qreal ringOrbitalDistance)
{

	if (qFuzzyCompare(this->m_ringOrbitalDistance, ringOrbitalDistance))
		return;

	this->m_ringOrbitalDistance = ringOrbitalDistance;
	emit ringOrbitalDistanceChanged(this->m_ringOrbitalDistance);
}

void Values::setRingOrbitalDistanceVariance(qreal ringOrbitalDistanceVariance)
{

	if (qFuzzyCompare(this->m_ringOrbitalDistanceVariance, ringOrbitalDistanceVariance))
		return;

	this->m_ringOrbitalDistanceVariance = ringOrbitalDistanceVariance;
	emit ringOrbitalDistanceVarianceChanged(this->m_ringOrbitalDistanceVariance);
}

void Values::setRingDensityFactor(qreal ringDensityFactor)
{

	if (qFuzzyCompare(this->m_ringDensityFactor, ringDensityFactor))
		return;

	this->m_ringDensityFactor = ringDensityFactor;
	emit ringDensityFactorChanged(this->m_ringDensityFactor);
}

void Values::setRingRotationTimeVariance(qreal ringRotationTimeVariance)
{

	if (qFuzzyCompare(this->m_ringRotationTimeVariance, ringRotationTimeVariance))
		return;

	this->m_ringRotationTimeVariance = ringRotationTimeVariance;
	emit ringRotationTimeVarianceChanged(this->m_ringRotationTimeVariance);
}

void Values::setMoonCountVariance(qreal moonCountVariance)
{
	if (qFuzzyCompare(this->m_moonCountVariance, moonCountVariance))
		return;

	this->m_moonCountVariance = moonCountVariance;
	emit moonCountVarianceChanged(this->m_moonCountVariance);
}

void Values::setMoonBaseSizeFactor(qreal moonBaseSizeFactor)
{

	if (qFuzzyCompare(this->m_moonBaseSizeFactor, moonBaseSizeFactor))
		return;

	this->m_moonBaseSizeFactor = moonBaseSizeFactor;
	emit moonBaseSizeFactorChanged(this->m_moonBaseSizeFactor);
}

void Values::setMoonSizeVariance(qreal moonSizeVariance)
{

	if (qFuzzyCompare(this->m_moonSizeVariance, moonSizeVariance))
		return;

	this->m_moonSizeVariance = moonSizeVariance;
	emit moonSizeVarianceChanged(this->m_moonSizeVariance);
}

void Values::setMoonOrbitalDistanceVariance(qreal moonOrbitalDistanceVariance)
{

	if (qFuzzyCompare(this->m_moonOrbitalDistanceVariance, moonOrbitalDistanceVariance))
		return;

	this->m_moonOrbitalDistanceVariance = moonOrbitalDistanceVariance;
	emit moonOrbitalDistanceVarianceChanged(this->m_moonOrbitalDistanceVariance);
}

void Values::setMoonCountToPlanetSizeFactor(qreal moonCountToPlanetSizeFactor)
{

	if (qFuzzyCompare(m_moonCountToPlanetSizeFactor, moonCountToPlanetSizeFactor))
		return;

	m_moonCountToPlanetSizeFactor = moonCountToPlanetSizeFactor;
	emit moonCountToPlanetSizeFactorChanged(m_moonCountToPlanetSizeFactor);
}

void Values::setMoonAngleVariance(qreal moonAngleVariance)
{

	if (qFuzzyCompare(this->m_moonAngleVariance, moonAngleVariance))
		return;

	this->m_moonAngleVariance = moonAngleVariance;
	emit moonAngleVarianceChanged(this->m_moonAngleVariance);
}

void Values::setTerrainE0(qreal terrainE0)
{

	if (qFuzzyCompare(this->m_terrainE0, terrainE0))
		return;

	this->m_terrainE0 = terrainE0;
	emit terrainE0Changed(this->m_terrainE0);
}

void Values::setTerrainE1(qreal terrainE1)
{

	if (qFuzzyCompare(this->m_terrainE1, terrainE1))
		return;

	this->m_terrainE1 = terrainE1;
	emit terrainE1Changed(this->m_terrainE1);
}

void Values::setTerrainE2(qreal terrainE2)
{

	if (qFuzzyCompare(this->m_terrainE2, terrainE2))
		return;

	this->m_terrainE2 = terrainE2;
	emit terrainE2Changed(this->m_terrainE2);
}

void Values::setTerrainE3(qreal terrainE3)
{

	if (qFuzzyCompare(this->m_terrainE3, terrainE3))
		return;

	this->m_terrainE3 = terrainE3;
	emit terrainE3Changed(this->m_terrainE3);
}

void Values::setTerrainE4(qreal terrainE4)
{

	if (qFuzzyCompare(this->m_terrainE4, terrainE4))
		return;

	this->m_terrainE4 = terrainE4;
	emit terrainE4Changed(this->m_terrainE4);
}

void Values::setTerrainExp(qreal terrainExp)
{

	if (qFuzzyCompare(this->m_terrainExp, terrainExp))
		return;

	this->m_terrainExp = terrainExp;
	emit terrainExpChanged(this->m_terrainExp);
}

void Values::setTerrainSeed(int terrainSeed)
{
	if (this->m_terrainSeed == terrainSeed)
		return;

	this->m_terrainSeed = terrainSeed;
	emit terrainSeedChanged(this->m_terrainSeed);
}

void Values::setTerrainPlanetScale(qreal terrainPlanetScale)
{
	if (qFuzzyCompare(this->m_terrainPlanetScale, terrainPlanetScale))
		return;

	this->m_terrainPlanetScale = terrainPlanetScale;
	emit terrainPlanetScaleChanged(this->m_terrainPlanetScale);
}

void Values::setDisplayHeight(bool displayHeight)
{
	if (this->m_displayHeight == displayHeight)
		return;

	this->m_displayHeight = displayHeight;
	emit displayHeightChanged(this->m_displayHeight);
}

void Values::setTerrainOctaves(int terrainOctaves)
{
	if (this->m_terrainOctaves == terrainOctaves)
		return;

	this->m_terrainOctaves = terrainOctaves;
	emit terrainOctavesChanged(this->m_terrainOctaves);
}

void Values::setTerrainColdness(qreal terrainColdness)
{
	if (qFuzzyCompare(this->m_terrainColdness, terrainColdness))
		return;

	this->m_terrainColdness = terrainColdness;
	emit terrainColdnessChanged(this->m_terrainColdness);
}

void Values::setTerrainSeaLevelFactor(qreal terrainSeaLevelFactor)
{
	if (qFuzzyCompare(this->m_terrainSeaLevelFactor, terrainSeaLevelFactor))
		return;

	this->m_terrainSeaLevelFactor = terrainSeaLevelFactor;
	emit terrainSeaLevelFactorChanged(this->m_terrainSeaLevelFactor);
}

void Values::setTerrainHeightFactor(qreal terrainHeightFactor)
{

	if (qFuzzyCompare(this->m_terrainHeightFactor, terrainHeightFactor))
		return;

	this->m_terrainHeightFactor = terrainHeightFactor;
	emit terrainHeightFactorChanged(this->m_terrainHeightFactor);
}

void Values::setRingAngleVariance(qreal ringAngleVariance)
{

	if (qFuzzyCompare(this->m_ringAngleVariance, ringAngleVariance))
		return;

	this->m_ringAngleVariance = ringAngleVariance;
	emit ringAngleVarianceChanged(this->m_ringAngleVariance);
}

void Values::setRingBaseColor(QColor ringBaseColor)
{
	if (this->m_ringBaseColor == ringBaseColor)
		return;

	this->m_ringBaseColor = ringBaseColor;
	emit ringBaseColorChanged(this->m_ringBaseColor);
}

qreal Values::ringBaseRotationTime() const
{
	return this->m_ringBaseRotationTime;
}

qreal Values::ringRotationTimeVariance() const
{
	return this->m_ringRotationTimeVariance;
}

void Values::setRingBaseRotationTime(qreal ringBaseRotationTime)
{

	if (qFuzzyCompare(this->m_ringBaseRotationTime, ringBaseRotationTime))
		return;

	this->m_ringBaseRotationTime = ringBaseRotationTime;
	emit ringBaseRotationTimeChanged(this->m_ringBaseRotationTime);
}

void Values::setRockBaseSize(qreal rockBaseSize)
{

	if (qFuzzyCompare(this->m_rockBaseSize, rockBaseSize))
		return;

	this->m_rockBaseSize = rockBaseSize;
	emit rockBaseSizeChanged(this->m_rockBaseSize);
}

void Values::setRockSizeVariance(qreal rockSizeVariance)
{

	if (qFuzzyCompare(this->m_rockSizeVariance, rockSizeVariance))
		return;

	this->m_rockSizeVariance = rockSizeVariance;
	emit rockSizeVarianceChanged(this->m_rockSizeVariance);
}

void Values::setRockOrbitalDistanceVariance(qreal rockOrbitalDistanceVariance)
{

	if (qFuzzyCompare(this->m_rockOrbitalDistanceVariance, rockOrbitalDistanceVariance))
		return;

	this->m_rockOrbitalDistanceVariance = rockOrbitalDistanceVariance;
	emit rockOrbitalDistanceVarianceChanged(this->m_rockOrbitalDistanceVariance);
}

void Values::setRockHeightVariance(qreal rockHeightVariance)
{

	if (qFuzzyCompare(this->m_rockHeightVariance, rockHeightVariance))
		return;

	this->m_rockHeightVariance = rockHeightVariance;
	emit rockHeightVarianceChanged(this->m_rockHeightVariance);
}

void Values::setRockColorVariance(qreal rockColorVariance)
{

	if (qFuzzyCompare(this->m_rockColorVariance, rockColorVariance))
		return;

	this->m_rockColorVariance = rockColorVariance;
	emit rockColorVarianceChanged(this->m_rockColorVariance);
}

qreal Values::rockBaseSize() const
{
	return this->m_rockBaseSize;
}

qreal Values::rockSizeVariance() const
{
	return this->m_rockSizeVariance;
}

qreal Values::rockOrbitalDistanceVariance() const
{
	return this->m_rockOrbitalDistanceVariance;
}

qreal Values::rockHeightVariance() const
{
	return this->m_rockHeightVariance;
}

qreal Values::rockColorVariance() const
{
	return this->m_rockColorVariance;
}

qreal Values::moonCountVariance() const
{
	return this->m_moonCountVariance;
}

qreal Values::moonBaseSizeFactor() const
{
	return this->m_moonBaseSizeFactor;
}

qreal Values::moonSizeVariance() const
{
	return this->m_moonSizeVariance;
}

qreal Values::moonOrbitalDistanceVariance() const
{
	return this->m_moonOrbitalDistanceVariance;
}

qreal Values::moonCountToPlanetSizeFactor() const
{
	return this->m_moonCountToPlanetSizeFactor;
}

qreal Values::moonAngleVariance() const
{
	return this->m_moonAngleVariance;
}

qreal Values::terrainE0() const
{
	return this->m_terrainE0;
}

qreal Values::terrainE1() const
{
	return this->m_terrainE1;
}

qreal Values::terrainE2() const
{
	return this->m_terrainE2;
}

qreal Values::terrainE3() const
{
	return this->m_terrainE3;
}

qreal Values::terrainE4() const
{
	return this->m_terrainE4;
}

qreal Values::terrainExp() const
{
	return this->m_terrainExp;
}

qreal Values::terrainHeightFactor() const
{
	return this->m_terrainHeightFactor;
}

int Values::terrainSeed() const
{
	return this->m_terrainSeed;
}

qreal Values::terrainPlanetScale() const
{
	return this->m_terrainPlanetScale;
}

bool Values::displayHeight() const
{
	return this->m_displayHeight;
}

int Values::terrainOctaves() const
{
	return this->m_terrainOctaves;
}

qreal Values::terrainColdness() const
{
	return this->m_terrainColdness;
}

qreal Values::terrainSeaLevelFactor() const
{
	return this->m_terrainSeaLevelFactor;
}

}
