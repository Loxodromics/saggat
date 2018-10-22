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

	/// Planet
	Q_PROPERTY(qreal planetBaseRadius READ planetBaseRadius WRITE setPlanetBaseRadius NOTIFY planetBaseRadiusChanged)
	Q_PROPERTY(qreal planetRadiusVariance READ planetRadiusVariance WRITE setPlanetRadiusVariance NOTIFY planetRadiusVarianceChanged)
	Q_PROPERTY(int planetBaseRotationDuration READ planetBaseRotationDuration WRITE setPlanetBaseRotationDuration NOTIFY planetBaseRotationDurationChanged)
	Q_PROPERTY(int planetRotationDurationVariance READ planetRotationDurationVariance WRITE setPlanetRotationDurationVariance NOTIFY planetRotationDurationVarianceChanged)
	Q_PROPERTY(int planetMinRotationDuration READ planetMinRotationDuration WRITE setPlanetMinRotationDuration NOTIFY planetMinRotationDurationChanged)

	/// Rings
	Q_PROPERTY(qreal ringBaseWidth READ ringBaseWidth WRITE setRingBaseWidth NOTIFY ringBaseWidthChanged)
	Q_PROPERTY(qreal ringWidthVariance READ ringWidthVariance WRITE setRingWidthVariance NOTIFY ringWidthVarianceChanged)
	Q_PROPERTY(qreal ringOrbitalDistance READ ringOrbitalDistance WRITE setRingOrbitalDistance NOTIFY ringOrbitalDistanceChanged)
	Q_PROPERTY(qreal ringOrbitalDistanceVariance READ ringOrbitalDistanceVariance WRITE setRingOrbitalDistanceVariance NOTIFY ringOrbitalDistanceVarianceChanged)
	Q_PROPERTY(qreal ringDensityFactor READ ringDensityFactor WRITE setRingDensityFactor NOTIFY ringDensityFactorChanged)
	Q_PROPERTY(QColor ringBaseColor READ ringBaseColor WRITE setRingBaseColor NOTIFY ringBaseColorChanged)
	Q_PROPERTY(qreal ringBaseRotationTime READ ringBaseRotationTime WRITE setRingBaseRotationTime NOTIFY ringBaseRotationTimeChanged)
	Q_PROPERTY(qreal ringRotationTimeVariance READ ringRotationTimeVariance WRITE setRingRotationTimeVariance NOTIFY ringRotationTimeVarianceChanged)

	/// Rocks
	Q_PROPERTY(qreal rockBaseSize READ rockBaseSize WRITE setRockBaseSize NOTIFY rockBaseSizeChanged)
	Q_PROPERTY(qreal rockSizeVariance READ rockSizeVariance WRITE setRockSizeVariance NOTIFY rockSizeVarianceChanged)
	Q_PROPERTY(qreal rockOrbitalDistanceVariance READ rockOrbitalDistanceVariance WRITE setRockOrbitalDistanceVariance NOTIFY rockOrbitalDistanceVarianceChanged)
	Q_PROPERTY(qreal rockHeightVariance READ rockHeightVariance WRITE setRockHeightVariance NOTIFY rockHeightVarianceChanged)
	Q_PROPERTY(qreal rockColorVariance READ rockColorVariance WRITE setRockColorVariance NOTIFY rockColorVarianceChanged)

	/// Moons
	Q_PROPERTY(qreal moonCountVariance READ moonCountVariance WRITE setMoonCountVariance NOTIFY moonCountVarianceChanged)
	Q_PROPERTY(qreal moonBaseSizeFactor READ moonBaseSizeFactor WRITE setMoonBaseSizeFactor NOTIFY moonBaseSizeFactorChanged)
	Q_PROPERTY(qreal moonSizeVariance READ moonSizeVariance WRITE setMoonSizeVariance NOTIFY moonSizeVarianceChanged)
	Q_PROPERTY(qreal moonOrbitalDistanceVariance READ moonOrbitalDistanceVariance WRITE setMoonOrbitalDistanceVariance NOTIFY moonOrbitalDistanceVarianceChanged)
	Q_PROPERTY(qreal moonCountToPlanetSizeFactor READ moonCountToPlanetSizeFactor WRITE setMoonCountToPlanetSizeFactor NOTIFY moonCountToPlanetSizeFactorChanged)

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
	qreal ringBaseRotationTime() const;
	qreal ringRotationTimeVariance() const;
	qreal rockBaseSize() const;
	qreal rockSizeVariance() const;
	qreal rockOrbitalDistanceVariance() const;
	qreal rockHeightVariance() const;
	qreal rockColorVariance() const;
	qreal moonCountVariance() const;
	qreal moonBaseSizeFactor() const;
	qreal moonSizeVariance() const;
	qreal moonOrbitalDistanceVariance() const;
	qreal moonCountToPlanetSizeFactor() const;

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
	void setRockBaseSize(qreal rockBaseSize);
	void setRockSizeVariance(qreal rockSizeVariance);
	void setRockOrbitalDistanceVariance(qreal rockOrbitalDistanceVariance);
	void setRockHeightVariance(qreal rockHeightVariance);
	void setRockColorVariance(qreal rockColorVariance);
	void setRingBaseRotationTime(qreal ringBaseRotationTime);
	void setRingRotationTimeVariance(qreal ringRotationTimeVariance);
	void setMoonCountVariance(qreal moonCountVariance);
	void setMoonBaseSizeFactor(qreal moonBaseSizeFactor);
	void setMoonSizeVariance(qreal moonSizeVariance);
	void setMoonOrbitalDistanceVariance(qreal moonOrbitalDistanceVariance);
	void setMoonCountToPlanetSizeFactor(qreal moonCountToPlanetSizeFactor);

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
	void rockBaseSizeChanged(qreal rockBaseSize);
	void rockSizeVarianceChanged(qreal rockSizeVariance);
	void rockOrbitalDistanceVarianceChanged(qreal rockOrbitalDistanceVariance);
	void rockHeightVarianceChanged(qreal rockHeightVariance);
	void rockColorVarianceChanged(qreal rockColorVariance);
	void ringBaseRotationTimeChanged(qreal ringBaseRotationTime);
	void ringRotationTimeVarianceChanged(qreal ringRotationTimeVariance);
	void moonCountVarianceChanged(qreal moonCountVariance);
	void moonBaseSizeFactorChanged(qreal moonBaseSizeFactor);
	void moonSizeVarianceChanged(qreal moonSizeVariance);
	void moonOrbitalDistanceVarianceChanged(qreal moonOrbitalDistanceVariance);
	void moonCountToPlanetSizeFactorChanged(qreal moonCountToPlanetSizeFactor);

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
	qreal m_ringBaseRotationTime;
	qreal m_ringRotationTimeVariance;
	qreal m_rockBaseSize;
	qreal m_rockSizeVariance;
	qreal m_rockOrbitalDistanceVariance;
	qreal m_rockHeightVariance;
	qreal m_rockColorVariance;
	qreal m_moonCountVariance;
	qreal m_moonBaseSizeFactor;
	qreal m_moonSizeVariance;
	qreal m_moonOrbitalDistanceVariance;
	qreal m_moonCountToPlanetSizeFactor;

private:
	explicit Values(QObject *parent = nullptr);
	Values(Values const&);
	void operator =(Values const&);
};

}

#endif // SAGGAT_VALUES_H
