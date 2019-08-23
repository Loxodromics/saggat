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

class PerlinNoiseElevationProvider : public ElevationProvider
{
public:
	explicit PerlinNoiseElevationProvider(unsigned int seed);

	virtual double elevationAt(const double x, const double y, const double z) override;

protected:
	PerlinNoise m_perlinElevation;
};

#endif // PERLINNOISEELEVATIONPROVIDER_H
