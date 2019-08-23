//
//  perlinnoiseelevationprovider.cpp
//  Saggat
//
//  Created by philipp on 23.08.2019.
//  Copyright (c) 2019 Philipp Engelhard. All rights reserved.
//
#include "perlinnoiseelevationprovider.h"

PerlinNoiseElevationProvider::PerlinNoiseElevationProvider(unsigned int seed)
	: m_perlinElevation(seed)
{

}

double PerlinNoiseElevationProvider::elevationAt(const double x, const double y, const double z)
{
	double elevation = m_e0 * this->noiseElevation(x, y, z);
	elevation += m_e1 *	this->noiseElevation(x * 2,  y * 2,  z * 2);
	elevation += m_e2 *	this->noiseElevation(x * 4,  y * 4,  z * 4);
	elevation += m_e3 *	this->noiseElevation(x * 8,  y * 8,  z * 8);
	elevation += m_e4 *	this->noiseElevation(x * 16, y * 16, z * 16);
	elevation += m_e5 *	this->noiseElevation(x * 32, y * 32, z * 32);


	return elevation;
}

double PerlinNoiseElevationProvider::noiseElevation(double x, double y, double z)
{
	/// magigic numbers to spread the values, "noise" doesn't range from 0 to 1
	return (this->m_perlinElevation.noise(x, y, z) - 0.363484) * (1/0.386516);
}
