//
//  elevationprovider.h
//  Saggat
//
//  Created by philipp on 23.08.2019.
//  Copyright (c) 2019 Philipp Engelhard. All rights reserved.
//
#ifndef ELEVATIONPROVIDER_H
#define ELEVATIONPROVIDER_H


class ElevationProvider
{
public:
	explicit ElevationProvider();
	virtual ~ElevationProvider() {}

	virtual double elevationAt(const double x, const double y, const double z);
};

#endif // ELEVATIONPROVIDER_H
