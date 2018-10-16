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
	  m_planetRotationDurationVariance(15000)
{

}

qreal Values::planetBaseRadius() const
{
	return this->m_planetBaseRadius;
}

qreal Values::planetRadiusVariance() const
{
	return m_planetRadiusVariance;
}

int Values::planetBaseRotationDuration() const
{
	return m_planetBaseRotationDuration;
}

int Values::planetRotationDurationVariance() const
{
	return m_planetRotationDurationVariance;
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
	if ( qFuzzyCompare(m_planetRadiusVariance, planetRadiusVariance) )
		return;

	m_planetRadiusVariance = planetRadiusVariance;
	emit planetRadiusVarianceChanged(m_planetRadiusVariance);
}

void Values::setPlanetBaseRotationDuration(int planetBaseRotationDuration)
{
	if ( m_planetBaseRotationDuration == planetBaseRotationDuration )
		return;

	m_planetBaseRotationDuration = planetBaseRotationDuration;
	emit planetBaseRotationDurationChanged(m_planetBaseRotationDuration);
}

void Values::setPlanetRotationDurationVariance(int planetRotationDurationVariance)
{
	qWarning("Floating point comparison needs context sanity check");
	if ( m_planetRotationDurationVariance == planetRotationDurationVariance )
		return;

	m_planetRotationDurationVariance = planetRotationDurationVariance;
	emit planetRotationDurationVarianceChanged(m_planetRotationDurationVariance);
}

}
