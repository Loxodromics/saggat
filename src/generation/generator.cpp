//
//  generator.cpp
//  Saggat
//
//  Created by philipp on 16.10.2018.
//  Copyright (c) 2018 Philipp Engelhard. All rights reserved.
//
#include "generator.h"
#include "src/common/values.h"
#include <cmath>

namespace Saggat {

Generator::Generator(QObject *parent)
	: QObject(parent)
{
	unsigned int seed = 444;
	m_gen = std::mt19937(seed);
}

qreal Generator::planetRadius()
{
	std::normal_distribution<> dist{Values::getInstance().planetBaseRadius(), Values::getInstance().planetRadiusVariance()};
	return dist(this->m_gen);
}

int Generator::planetRotationDuration()
{
	std::normal_distribution<> dist{double(Values::getInstance().planetBaseRotationDuration()), double(Values::getInstance().planetRotationDurationVariance())};
	return int(std::trunc(dist(this->m_gen)));
}

} // namespace Saggat
