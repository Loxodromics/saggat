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
	Q_PROPERTY(qreal ringAngleVariance READ ringAngleVariance WRITE setRingAngleVariance NOTIFY ringAngleVarianceChanged)

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
	Q_PROPERTY(qreal moonAngleVariance READ moonAngleVariance WRITE setMoonAngleVariance NOTIFY moonAngleVarianceChanged)

	/// Terrain
	Q_PROPERTY(qreal terrainE0 READ terrainE0 WRITE setTerrainE0 NOTIFY terrainE0Changed)
	Q_PROPERTY(qreal terrainE1 READ terrainE1 WRITE setTerrainE1 NOTIFY terrainE1Changed)
	Q_PROPERTY(qreal terrainE2 READ terrainE2 WRITE setTerrainE2 NOTIFY terrainE2Changed)
	Q_PROPERTY(qreal terrainE3 READ terrainE3 WRITE setTerrainE3 NOTIFY terrainE3Changed)
	Q_PROPERTY(qreal terrainE4 READ terrainE4 WRITE setTerrainE4 NOTIFY terrainE4Changed)
	Q_PROPERTY(qreal terrainExp READ terrainExp WRITE setTerrainExp NOTIFY terrainExpChanged)
	Q_PROPERTY(qreal terrainHeightFactor READ terrainHeightFactor WRITE setTerrainHeightFactor NOTIFY terrainHeightFactorChanged)
	Q_PROPERTY(int terrainSeed READ terrainSeed WRITE setTerrainSeed NOTIFY terrainSeedChanged)
	Q_PROPERTY(qreal terrainPlanetScale READ terrainPlanetScale WRITE setTerrainPlanetScale NOTIFY terrainPlanetScaleChanged)
	Q_PROPERTY(qreal terrainColdness READ terrainColdness WRITE setTerrainColdness NOTIFY terrainColdnessChanged)
	Q_PROPERTY(bool displayHeight READ displayHeight WRITE setDisplayHeight NOTIFY displayHeightChanged)
	Q_PROPERTY(int terrainOctaves READ terrainOctaves WRITE setTerrainOctaves NOTIFY terrainOctavesChanged)
	Q_PROPERTY(qreal terrainSeaLevel READ terrainSeaLevel WRITE setTerrainSeaLevel NOTIFY terrainSeaLevelChanged)

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
	qreal ringAngleVariance() const;

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
	qreal moonAngleVariance() const;

	qreal terrainE0() const;
	qreal terrainE1() const;
	qreal terrainE2() const;
	qreal terrainE3() const;
	qreal terrainE4() const;
	qreal terrainExp() const;
	qreal terrainHeightFactor() const;
	int terrainSeed() const;
	qreal terrainPlanetScale() const;
	bool displayHeight() const;
	int terrainOctaves() const;
	qreal terrainColdness() const;
	qreal terrainSeaLevel() const;

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
	void setRingAngleVariance(qreal ringAngleVariance);

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
	void setMoonAngleVariance(qreal moonAngleVariance);

	void setTerrainE0(qreal terrainE0);
	void setTerrainE1(qreal terrainE1);
	void setTerrainE2(qreal terrainE2);
	void setTerrainE3(qreal terrainE3);
	void setTerrainE4(qreal terrainE4);
	void setTerrainExp(qreal terrainExp);
	void setTerrainHeightFactor(qreal terrainHeightFactor);
	void setTerrainSeed(int terrainSeed);
	void setTerrainPlanetScale(qreal terrainPlanetScale);
	void setDisplayHeight(bool displayHeight);
	void setTerrainOctaves(int terrainOctaves);
	void setTerrainColdness(qreal terrainColdness);
	void setTerrainSeaLevel(qreal terrainSeaLevel);

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
	void ringBaseRotationTimeChanged(qreal ringBaseRotationTime);
	void ringRotationTimeVarianceChanged(qreal ringRotationTimeVariance);
	void ringAngleVarianceChanged(qreal ringAngleVariance);

	void rockBaseSizeChanged(qreal rockBaseSize);
	void rockSizeVarianceChanged(qreal rockSizeVariance);
	void rockOrbitalDistanceVarianceChanged(qreal rockOrbitalDistanceVariance);
	void rockHeightVarianceChanged(qreal rockHeightVariance);
	void rockColorVarianceChanged(qreal rockColorVariance);

	void moonCountVarianceChanged(qreal moonCountVariance);
	void moonBaseSizeFactorChanged(qreal moonBaseSizeFactor);
	void moonSizeVarianceChanged(qreal moonSizeVariance);
	void moonOrbitalDistanceVarianceChanged(qreal moonOrbitalDistanceVariance);
	void moonCountToPlanetSizeFactorChanged(qreal moonCountToPlanetSizeFactor);
	void moonAngleVarianceChanged(qreal moonAngleVariance);

	void terrainE0Changed(qreal terrainE0);
	void terrainE1Changed(qreal terrainE1);
	void terrainE2Changed(qreal terrainE2);
	void terrainE3Changed(qreal terrainE3);
	void terrainE4Changed(qreal terrainE4);
	void terrainExpChanged(qreal terrainExp);
	void terrainHeightFactorChanged(qreal terrainHeightFactor);
	void terrainSeedChanged(int terrainSeed);
	void terrainPlanetScaleChanged(qreal terrainPlanetScale);
	void coldnessChanged(qreal coldness);
	void displayHeightChanged(bool displayHeight);
	void terrainOctavesChanged(int terrainOctaves);
	void terrainColdnessChanged(qreal terrainColdness);
	void terrainSeaLevelChanged(qreal terrainSeaLevel);

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
	qreal m_ringAngleVariance;

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
	qreal m_moonAngleVariance;

	qreal m_terrainE0;
	qreal m_terrainE1;
	qreal m_terrainE2;
	qreal m_terrainE3;
	qreal m_terrainE4;
	qreal m_terrainExp;
	qreal m_terrainHeightFactor;
	int   m_terrainSeed;
	qreal m_terrainPlanetScale;
	bool  m_displayHeight;
	int   m_terrainOctaves;
	qreal m_terrainColdness;
	qreal m_terrainSeaLevel;

private:
	explicit Values(QObject *parent = nullptr);
	Values(Values const&);
	void operator =(Values const&);

};

}

#endif // SAGGAT_VALUES_H
