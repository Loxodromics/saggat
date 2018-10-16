//
//  values.h
//  Saggat
//
//  Created by philipp on 16.10.2018.
//  Copyright (c) 2018 Philipp Engelhard. All rights reserved.
//
#ifndef SAGGAT_VALUES_H
#define SAGGAT_VALUES_H

#include <QObject>

namespace Saggat {
class Values : public QObject
{
	Q_OBJECT

public:
	static Values& getInstance()
	{
		static Values instance;
		return instance;
	}

	Q_PROPERTY(qreal planetBaseRadius READ planetBaseRadius WRITE setPlanetBaseRadius NOTIFY planetBaseRadiusChanged)
	Q_PROPERTY(qreal planetRadiusVariance READ planetRadiusVariance WRITE setPlanetRadiusVariance NOTIFY planetRadiusVarianceChanged)
	Q_PROPERTY(int planetBaseRotationDuration READ planetBaseRotationDuration WRITE setPlanetBaseRotationDuration NOTIFY planetBaseRotationDurationChanged)
	Q_PROPERTY(int planetRotationDurationVariance READ planetRotationDurationVariance WRITE setPlanetRotationDurationVariance NOTIFY planetRotationDurationVarianceChanged)

	qreal planetBaseRadius() const;
	qreal planetRadiusVariance() const;
	int planetBaseRotationDuration() const;
	int planetRotationDurationVariance() const;

public slots:
	void setPlanetBaseRadius(qreal planetBaseRadius);
	void setPlanetRadiusVariance(qreal planetRadiusVariance);
	void setPlanetBaseRotationDuration(int planetBaseRotationDuration);
	void setPlanetRotationDurationVariance(int planetRotationDurationVariance);

signals:
	void planetBaseRadiusChanged(qreal planetBaseRadius);
	void planetRadiusVarianceChanged(qreal planetRadiusVariance);
	void planetBaseRotationDurationChanged(int planetBaseRotationDuration);
	void planetRotationDurationVarianceChanged(int planetRotationDurationVariance);

protected:
	qreal m_planetBaseRadius;
	qreal m_planetRadiusVariance;
	int m_planetBaseRotationDuration;
	int m_planetRotationDurationVariance;

private:
	explicit Values(QObject *parent = nullptr);
	Values(Values const&);
	void operator =(Values const&);
};

}

#endif // SAGGAT_VALUES_H
