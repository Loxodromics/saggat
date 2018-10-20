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
	std::normal_distribution<> dist{Values::getInstance().planetBaseRadius(),
				Values::getInstance().planetRadiusVariance()};
	return dist(this->m_gen);
}

int Generator::planetRotationDuration()
{
	std::normal_distribution<> dist{double(Values::getInstance().planetBaseRotationDuration()),
				double(Values::getInstance().planetRotationDurationVariance())};
	return qMax(int(std::floor(dist(this->m_gen))), Values::getInstance().planetMinRotationDuration());
}

qreal Generator::ringWidth()
{
	std::normal_distribution<> dist{Values::getInstance().ringBaseWidth(),
				Values::getInstance().ringWidthVariance()};
	return qMax(dist(this->m_gen), 0.1);
}

qreal Generator::ringOrbitalDistance(qreal offset)
{
	std::normal_distribution<> dist{offset + Values::getInstance().ringOrbitalDistance(),
				Values::getInstance().ringOrbitalDistanceVariance()};
	return dist(this->m_gen);
}

int Generator::ringNumberOfRocks(qreal ringWidth, qreal orbitalDistance)
{
	//TODO: some randomness
	return int(std::floor(ringWidth * orbitalDistance *
						  Values::getInstance().ringDensityFactor() * Values::getInstance().ringDensityFactor()));
}

qreal Generator::ringAxis()
{
	std::uniform_real_distribution<> dist{0.0, 1.0};
	return qMax(qMin(dist(this->m_gen), 1.0), 0.0);
}

qreal Generator::ringAngle()
{
	std::normal_distribution<> dist{0, 10};
	return qMax(qMin(dist(this->m_gen), 90.0), -90.0);
}

QColor Generator::ringColor()
{
	std::uniform_real_distribution<> dist(0.0, 1.0);
	QColor color;
	color.setHslF(dist(this->m_gen), 0.8, 0.6);
	return color;
}

qreal Generator::ringRotationDuration()
{
	std::normal_distribution<> dist{Values::getInstance().ringBaseRotationTime(),
				Values::getInstance().ringRotationTimeVariance()};
	return qMax(dist(this->m_gen), 1000.0);
}

qreal Generator::rockSize()
{
	std::normal_distribution<> dist{Values::getInstance().rockBaseSize(),
				Values::getInstance().rockSizeVariance()};
	return qMax(dist(this->m_gen), 0.01);
}

qreal Generator::rockHeight()
{
	std::normal_distribution<> dist{0.0,
				Values::getInstance().rockHeightVariance()};
	return dist(this->m_gen);
}

qreal Generator::rockColor(qreal base)
{
	std::normal_distribution<> dist{base,
									Values::getInstance().rockColorVariance()};
	return dist(this->m_gen);
}

} // namespace Saggat
