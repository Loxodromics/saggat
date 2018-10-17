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
	  m_planetBaseRotationDuration(30000),
	  m_planetRotationDurationVariance(15000),
	  m_planetMinRotationDuration(1000),
	  m_ringBaseWidth(5.0),
	  m_ringWidthVariance(4.0),
	  m_ringOrbitalDistance(7.0),
	  m_ringOrbitalDistanceVariance(3.0),
	  m_ringDensityFactor(3.0),
	  m_ringBaseColor(QColor())
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

void Values::setRingBaseColor(QColor ringBaseColor)
{
	if (this->m_ringBaseColor == ringBaseColor)
		return;

	this->m_ringBaseColor = ringBaseColor;
	emit ringBaseColorChanged(this->m_ringBaseColor);
}

}
