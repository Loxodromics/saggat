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
#include <QColor>

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
	Q_PROPERTY(int planetMinRotationDuration READ planetMinRotationDuration WRITE setPlanetMinRotationDuration NOTIFY planetMinRotationDurationChanged)

	Q_PROPERTY(qreal ringBaseWidth READ ringBaseWidth WRITE setRingBaseWidth NOTIFY ringBaseWidthChanged)
	Q_PROPERTY(qreal ringWidthVariance READ ringWidthVariance WRITE setRingWidthVariance NOTIFY ringWidthVarianceChanged)
	Q_PROPERTY(qreal ringOrbitalDistance READ ringOrbitalDistance WRITE setRingOrbitalDistance NOTIFY ringOrbitalDistanceChanged)
	Q_PROPERTY(qreal ringOrbitalDistanceVariance READ ringOrbitalDistanceVariance WRITE setRingOrbitalDistanceVariance NOTIFY ringOrbitalDistanceVarianceChanged)
	Q_PROPERTY(qreal ringDensityFactor READ ringDensityFactor WRITE setRingDensityFactor NOTIFY ringDensityFactorChanged)
	Q_PROPERTY(QColor ringBaseColor READ ringBaseColor WRITE setRingBaseColor NOTIFY ringBaseColorChanged)

	qreal planetBaseRadius() const;
	qreal planetRadiusVariance() const;
	int planetBaseRotationDuration() const;
	int planetRotationDurationVariance() const;
	int planetMinRotationDuration() const;
	qreal ringBaseWidth() const;
	qreal ringWidthVariance() const;
	qreal ringOrbitalDistance() const;
	qreal ringOrbitalDistanceVariance() const;
	qreal ringDensityFactor() const;
	QColor ringBaseColor() const;


public slots:
	void setPlanetBaseRadius(qreal planetBaseRadius);
	void setPlanetRadiusVariance(qreal planetRadiusVariance);
	void setPlanetBaseRotationDuration(int planetBaseRotationDuration);
	void setPlanetRotationDurationVariance(int planetRotationDurationVariance);
	void setPlanetMinRotationDuration(int planetMinRotationDuration);
	void setRingBaseWidth(qreal ringBaseWidth);
	void setRingWidthVariance(qreal ringWidthVariance);
	void setRingOrbitalDistance(qreal ringOrbitalDistance);
	void setRingOrbitalDistanceVariance(qreal ringOrbitalDistanceVariance);
	void setRingDensityFactor(qreal ringDensityFactor);
	void setRingBaseColor(QColor ringBaseColor);


signals:
	void planetBaseRadiusChanged(qreal planetBaseRadius);
	void planetRadiusVarianceChanged(qreal planetRadiusVariance);
	void planetBaseRotationDurationChanged(int planetBaseRotationDuration);
	void planetRotationDurationVarianceChanged(int planetRotationDurationVariance);
	void planetMinRotationDurationChanged(int planetMinRotationDuration);
	void ringBaseWidthChanged(qreal ringBaseWidth);
	void ringWidthVarianceChanged(qreal ringWidthVariance);
	void ringOrbitalDistanceChanged(qreal ringOrbitalDistance);
	void ringOrbitalDistanceVarianceChanged(qreal ringOrbitalDistanceVariance);
	void ringDensityFactorChanged(qreal ringDensityFactor);
	void ringBaseColorChanged(QColor ringBaseColor);


protected:
	qreal m_planetBaseRadius;
	qreal m_planetRadiusVariance;
	int m_planetBaseRotationDuration;
	int m_planetRotationDurationVariance;
	int m_planetMinRotationDuration;
	qreal m_ringBaseWidth;
	qreal m_ringWidthVariance;
	qreal m_ringOrbitalDistance;
	qreal m_ringOrbitalDistanceVariance;
	qreal m_ringDensityFactor;
	QColor m_ringBaseColor;

private:
	explicit Values(QObject *parent = nullptr);
	Values(Values const&);
	void operator =(Values const&);

};

}

#endif // SAGGAT_VALUES_H
