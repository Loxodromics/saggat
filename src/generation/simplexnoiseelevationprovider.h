//
//  simplexnoiseelevationprovider.h
//  Saggat
//
//  Created by philipp on 25.08.2019.
//  Copyright (c) 2019 Philipp Engelhard. All rights reserved.
//
#ifndef SIMPLEXNOISEELEVATIONPROVIDER_H
#define SIMPLEXNOISEELEVATIONPROVIDER_H

#include "elevationprovider.h"
#include "src/thirdparty/simplexnoise.h"


namespace Saggat {

class SimplexNoiseElevationProvider : public ElevationProvider {
public:
	explicit SimplexNoiseElevationProvider(unsigned int seed, unsigned int octaves);

	virtual double elevationAt(const double x, const double y, const double z) override;

protected:
	double avoidZero(const double value);
	SimplexNoise m_simplexElevation;
	unsigned int m_octaves;

	/// Debug
	double m_min = 99999.9;
	double m_max = 0.0;
};
}	/// namespace Saggat

#endif	// SIMPLEXNOISEELEVATIONPROVIDER_H
