//
//  simplexnoiseelevationprovider.cpp
//  Saggat
//
//  Created by philipp on 25.08.2019.
//  Copyright (c) 2019 Philipp Engelhard. All rights reserved.
//
#include "simplexnoiseelevationprovider.h"
#include "src/common/values.h"

#include <cmath>
#include <QDebug>

namespace Saggat {
SimplexNoiseElevationProvider::SimplexNoiseElevationProvider(unsigned int seed, unsigned int octaves)
	: m_simplexElevation(seed)
	, m_octaves(octaves)
{

}

double SimplexNoiseElevationProvider::elevationAt(const double x, const double y, const double z)
{
	double newX = this->avoidZero(x);
	double newY = this->avoidZero(y);
	double newZ = this->avoidZero(z);
	/// magic numbers to get the a range that is _roughly_ [0, 1], that's good enough
	double elevation = this->m_simplexElevation.fractal(this->m_octaves, newX, newY, newZ) / 1.3 + 0.45;

	elevation = pow(elevation, Values::getInstance().terrainExp());

	/// sea level cut off
	if (elevation < static_cast<float>(Values::getInstance().terrainSeaLevel()))
		elevation = static_cast<float>(Values::getInstance().terrainSeaLevel());

	if (elevation > m_max) {
		m_max = elevation;
		qDebug() << "min: " << m_min << "max: " << m_max;
	}

	if (elevation < m_min) {
		m_min = elevation;
		qDebug() << "min: " << m_min << "max: " << m_max;
	}

	return elevation;
}

double SimplexNoiseElevationProvider::avoidZero(const double value)
{
	if ((value > -0.00001) && (value < 0.00001))
		return 0.0002;
	else
		return value;
}

} /// namespace Saggat
