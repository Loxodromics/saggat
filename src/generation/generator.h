//
//  generator.h
//  Saggat
//
//  Created by philipp on 16.10.2018.
//  Copyright (c) 2018 Philipp Engelhard. All rights reserved.
//
#ifndef SAGGAT_GENERATOR_H
#define SAGGAT_GENERATOR_H

#include <QObject>
#include <QColor>
#include <random>

namespace Saggat {

class Generator : public QObject
{
	Q_OBJECT

public:
	static Generator& getInstance()
	{
		static Generator instance;
		return instance;
	}

	/// Planet
	Q_INVOKABLE qreal	planetRadius();
	Q_INVOKABLE int		planetRotationDuration();

	/// Rings
	Q_INVOKABLE qreal	ringWidth();
	Q_INVOKABLE qreal	ringOrbitalDistance(qreal offset);
	Q_INVOKABLE int		ringNumberOfRocks(qreal ringWidth, qreal orbitalDistance);
	Q_INVOKABLE qreal	ringAxis();
	Q_INVOKABLE qreal	ringAngle();
	Q_INVOKABLE QColor	ringColor();
	Q_INVOKABLE qreal	ringRotationDuration();

	/// Rocks
	Q_INVOKABLE qreal	rockSize();
	Q_INVOKABLE qreal	rockHeight();
	Q_INVOKABLE qreal	rockColor(qreal base);
	Q_INVOKABLE qreal	rockOrbitalDistance(qreal base);

	/// Moons
	Q_INVOKABLE int		moonCount(qreal planetSize);
	Q_INVOKABLE qreal	moonSize(qreal planetSize);
	Q_INVOKABLE qreal	moonOrbitalDistance(qreal planetSize, qreal moonSize);
	Q_INVOKABLE	int moonRotationDuration(qreal planetSize, qreal moonSize, qreal moonOrbitalDisance);

protected:
	std::mt19937 m_gen;

private:
	explicit Generator(QObject *parent = nullptr);
	Generator(Generator const&);
	void operator =(Generator const&);
};

} // namespace Saggat

#endif // SAGGAT_GENERATOR_H
