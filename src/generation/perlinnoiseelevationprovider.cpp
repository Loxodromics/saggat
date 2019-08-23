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
	return this->m_perlinElevation.noise(x, y, z);
}
