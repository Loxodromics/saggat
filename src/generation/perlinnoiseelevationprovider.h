//
//  perlinnoiseelevationprovider.h
//  Saggat
//
//  Created by philipp on 23.08.2019.
//  Copyright (c) 2019 Philipp Engelhard. All rights reserved.
//
#ifndef PERLINNOISEELEVATIONPROVIDER_H
#define PERLINNOISEELEVATIONPROVIDER_H

#include "src/generation/elevationprovider.h"
#include "src/thirdparty/perlinnoise.h"

namespace Saggat {

class PerlinNoiseElevationProvider : public ElevationProvider
{
public:
	explicit PerlinNoiseElevationProvider(unsigned int seed);

	virtual double elevationAt(const double x, const double y, const double z) override;

protected:
	double noiseElevation(double x, double y, double z);

	PerlinNoise m_perlinElevation;
	double m_e0 = 1.00;
	double m_e1 = 0.50;
	double m_e2 = 0.25;
	double m_e3 = 0.13;
	double m_e4 = 0.06;
	double m_e5 = 0.03;

	double m_min = 99999.9;
	double m_max = 0.0;
};

} /// namespace Saggat

#endif // PERLINNOISEELEVATIONPROVIDER_H
