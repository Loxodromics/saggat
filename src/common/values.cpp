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
	  m_moonAngleVariance(10.0)
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

void Values::setPlanetBaseRadius(qreal planetBaseRadius)
{
	qWarning("Floating point comparison needs context sanity check");
	if ( qFuzzyCompare(this->m_planetBaseRadius, planetBaseRadius) )
		return;

	this->m_planetBaseRadius = planetBaseRadius;
	emit planetBaseRadiusChanged(this->m_planetBaseRadius);
}

void Values::setPlanetRadiusVariance(qreal planetRadiusVariance)
{
	qWarning("Floating point comparison needs context sanity check");
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
	qWarning("Floating point comparison needs context sanity check");
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
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(this->m_ringBaseWidth, ringBaseWidth))
		return;

	this->m_ringBaseWidth = ringBaseWidth;
	emit ringBaseWidthChanged(this->m_ringBaseWidth);
}

void Values::setRingWidthVariance(qreal ringWidthVariance)
{
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(this->m_ringWidthVariance, ringWidthVariance))
		return;

	this->m_ringWidthVariance = ringWidthVariance;
	emit ringWidthVarianceChanged(this->m_ringWidthVariance);
}

void Values::setRingOrbitalDistance(qreal ringOrbitalDistance)
{
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(this->m_ringOrbitalDistance, ringOrbitalDistance))
		return;

	this->m_ringOrbitalDistance = ringOrbitalDistance;
	emit ringOrbitalDistanceChanged(this->m_ringOrbitalDistance);
}

void Values::setRingOrbitalDistanceVariance(qreal ringOrbitalDistanceVariance)
{
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(this->m_ringOrbitalDistanceVariance, ringOrbitalDistanceVariance))
		return;

	this->m_ringOrbitalDistanceVariance = ringOrbitalDistanceVariance;
	emit ringOrbitalDistanceVarianceChanged(this->m_ringOrbitalDistanceVariance);
}

void Values::setRingDensityFactor(qreal ringDensityFactor)
{
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(this->m_ringDensityFactor, ringDensityFactor))
		return;

	this->m_ringDensityFactor = ringDensityFactor;
	emit ringDensityFactorChanged(this->m_ringDensityFactor);
}

void Values::setRingRotationTimeVariance(qreal ringRotationTimeVariance)
{
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(this->m_ringRotationTimeVariance, ringRotationTimeVariance))
		return;

	this->m_ringRotationTimeVariance = ringRotationTimeVariance;
	emit ringRotationTimeVarianceChanged(this->m_ringRotationTimeVariance);
}

void Values::setMoonCountVariance(qreal moonCountVariance)
{
	if (this->m_moonCountVariance == moonCountVariance)
		return;

	this->m_moonCountVariance = moonCountVariance;
	emit moonCountVarianceChanged(this->m_moonCountVariance);
}

void Values::setMoonBaseSizeFactor(qreal moonBaseSizeFactor)
{
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(this->m_moonBaseSizeFactor, moonBaseSizeFactor))
		return;

	this->m_moonBaseSizeFactor = moonBaseSizeFactor;
	emit moonBaseSizeFactorChanged(this->m_moonBaseSizeFactor);
}

void Values::setMoonSizeVariance(qreal moonSizeVariance)
{
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(this->m_moonSizeVariance, moonSizeVariance))
		return;

	this->m_moonSizeVariance = moonSizeVariance;
	emit moonSizeVarianceChanged(this->m_moonSizeVariance);
}

void Values::setMoonOrbitalDistanceVariance(qreal moonOrbitalDistanceVariance)
{
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(this->m_moonOrbitalDistanceVariance, moonOrbitalDistanceVariance))
		return;

	this->m_moonOrbitalDistanceVariance = moonOrbitalDistanceVariance;
	emit moonOrbitalDistanceVarianceChanged(this->m_moonOrbitalDistanceVariance);
}

void Values::setMoonCountToPlanetSizeFactor(qreal moonCountToPlanetSizeFactor)
{
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(m_moonCountToPlanetSizeFactor, moonCountToPlanetSizeFactor))
		return;

	m_moonCountToPlanetSizeFactor = moonCountToPlanetSizeFactor;
	emit moonCountToPlanetSizeFactorChanged(m_moonCountToPlanetSizeFactor);
}

void Values::setMoonAngleVariance(qreal moonAngleVariance)
{
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(this->m_moonAngleVariance, moonAngleVariance))
		return;

	this->m_moonAngleVariance = moonAngleVariance;
	emit moonAngleVarianceChanged(this->m_moonAngleVariance);
}

void Values::setRingAngleVariance(qreal ringAngleVariance)
{
	qWarning("Floating point comparison needs context sanity check");
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
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(this->m_ringBaseRotationTime, ringBaseRotationTime))
		return;

	this->m_ringBaseRotationTime = ringBaseRotationTime;
	emit ringBaseRotationTimeChanged(this->m_ringBaseRotationTime);
}

void Values::setRockBaseSize(qreal rockBaseSize)
{
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(this->m_rockBaseSize, rockBaseSize))
		return;

	this->m_rockBaseSize = rockBaseSize;
	emit rockBaseSizeChanged(this->m_rockBaseSize);
}

void Values::setRockSizeVariance(qreal rockSizeVariance)
{
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(this->m_rockSizeVariance, rockSizeVariance))
		return;

	this->m_rockSizeVariance = rockSizeVariance;
	emit rockSizeVarianceChanged(this->m_rockSizeVariance);
}

void Values::setRockOrbitalDistanceVariance(qreal rockOrbitalDistanceVariance)
{
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(this->m_rockOrbitalDistanceVariance, rockOrbitalDistanceVariance))
		return;

	this->m_rockOrbitalDistanceVariance = rockOrbitalDistanceVariance;
	emit rockOrbitalDistanceVarianceChanged(this->m_rockOrbitalDistanceVariance);
}

void Values::setRockHeightVariance(qreal rockHeightVariance)
{
	qWarning("Floating point comparison needs context sanity check");
	if (qFuzzyCompare(this->m_rockHeightVariance, rockHeightVariance))
		return;

	this->m_rockHeightVariance = rockHeightVariance;
	emit rockHeightVarianceChanged(this->m_rockHeightVariance);
}

void Values::setRockColorVariance(qreal rockColorVariance)
{
	qWarning("Floating point comparison needs context sanity check");
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

qreal Values::ringAngleVariance() const
{
	return this->m_ringAngleVariance;
}


}
