//
//  perlinnoiseelevationprovider.cpp
//  Saggat
//
//  Created by philipp on 23.08.2019.
//  Copyright (c) 2019 Philipp Engelhard. All rights reserved.
//
#include "perlinnoiseelevationprovider.h"
#include "src/common/values.h"

#include <QDebug>

#include <cmath>

namespace Saggat {

PerlinNoiseElevationProvider::PerlinNoiseElevationProvider(unsigned int seed)
	: m_perlinElevation(seed)
{
}

double PerlinNoiseElevationProvider::elevationAt(const double x, const double y, const double z)
{
	double elevation = 0.0;
	elevation += Values::getInstance().terrainE0() * this->noiseElevation(x, y, z);
	elevation += Values::getInstance().terrainE1() * this->noiseElevation(x * 2, y * 2, z * 2);
	elevation += Values::getInstance().terrainE2() * this->noiseElevation(x * 4, y * 4, z * 4);
	elevation += Values::getInstance().terrainE3() * this->noiseElevation(x * 8, y * 8, z * 8);
	elevation += Values::getInstance().terrainE4() * this->noiseElevation(x * 16, y * 16, z * 16);
	//  elevation += Values::getInstance().terrainE5() *
	//			   this->noiseElevation(x * 32, y * 32, z * 32);

	elevation /= Values::getInstance().terrainE0() + Values::getInstance().terrainE1()
	  + Values::getInstance().terrainE2() + Values::getInstance().terrainE3() + Values::getInstance().terrainE4();

	elevation = pow(elevation, Values::getInstance().terrainExp());

//	/// sea level cut off
//	if (elevation < 0.09)
//		elevation = 0.09;

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

double PerlinNoiseElevationProvider::noiseElevation(double x, double y, double z)
{
	/// magigic numbers to spread the values, "noise" doesn't range from 0 to 1
	return (this->m_perlinElevation.noise(x, y, z));// - 0.204689) * (1.0 / 0.612697);
	//0.612697
//	min:  0.218218 max:  0.767998
//	min:  0.26793 max:  0.768394
//	min:  0.320176 max:  0.784724
//	min:  0.204689 max:  0.817377
//	min:  0.147025 max:  0.779716
}

}	// namespace Saggat
