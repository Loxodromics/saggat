//
//  simplexnoiseelevationprovider.cpp
//  Saggat
//
//  Created by philipp on 25.08.2019.
//  Copyright (c) 2019 Philipp Engelhard. All rights reserved.
//
#include "simplexnoiseelevationprovider.h"
#include <QDebug>

namespace Saggat {
SimplexNoiseElevationProvider::SimplexNoiseElevationProvider(unsigned int octaves)
	: m_simplexElevation(1.0, 1.0)
	, m_octaves(octaves)

{

}

double SimplexNoiseElevationProvider::elevationAt(const double x, const double y, const double z)
{
	double newX = this->avoidZero(x);
	double newY = this->avoidZero(y);
	double newZ = this->avoidZero(z);
	/// magic numbers to get the a range that is _roughly_ [0, 1];
	double elevation = this->m_simplexElevation.fractal(this->m_octaves, newX, newY, newZ) / 1.3 + 0.45;

//	if (elevation > m_max) {
//		m_max = elevation;
//		qDebug() << "min: " << m_min << "max: " << m_max;
//	}

//	if (elevation < m_min) {
//		m_min = elevation;
//		qDebug() << "min: " << m_min << "max: " << m_max;
//	}

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
