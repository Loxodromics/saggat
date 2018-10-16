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

	Q_INVOKABLE qreal planetRadius();
	Q_INVOKABLE int planetRotationDuration();

protected:
//	std::random_device m_randomDevice;
	std::mt19937 m_gen;
//	std::normal_distribution<> m_normalDistribution;

private:
	explicit Generator(QObject *parent = nullptr);
	Generator(Generator const&);
	void operator =(Generator const&);
};

} // namespace Saggat

#endif // SAGGAT_GENERATOR_H
