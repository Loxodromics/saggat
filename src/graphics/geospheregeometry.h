//
//  geospheregeometry.h
//  Qt3D-Geosphere
//
//  Created by philipp on 08.08.2019.
//  Copyright (c) 2019 Philipp Engelhard. All rights reserved.
//
#ifndef GEOSPHEREGEOMETRY_H
#define GEOSPHEREGEOMETRY_H

#include "src/generation/perlinnoiseelevationprovider.h"
#include <Qt3DExtras/qt3dextras_global.h>
#include <Qt3DRender/qgeometry.h>

namespace Qt3DRender {

class QAttribute;
class QBuffer;

}	// namespace Qt3DRender

class GeosphereGeometry : public Qt3DRender::QGeometry {
	Q_OBJECT

	Q_PROPERTY(float radius READ radius WRITE setRadius NOTIFY radiusChanged)
	Q_PROPERTY(unsigned int subdivisions READ subdivisions WRITE setSubdivisions NOTIFY subdivisionsChanged)

public:
	explicit GeosphereGeometry(Qt3DCore::QNode* parent = nullptr);
	~GeosphereGeometry();

	Qt3DRender::QAttribute* positionAttribute() const;
	Qt3DRender::QAttribute* indexAttribute() const;
	Qt3DRender::QAttribute* normalAttribute() const;

	float radius() const;
	unsigned int subdivisions() const;

public slots:
	void setRadius(float radius);
	void setSubdivisions(unsigned int subdivisions);

signals:
	void radiusChanged(float radius);
	void subdivisionsChanged(unsigned int subdivisions);

protected:
	void init();
	void update();

	Qt3DRender::QAttribute* m_positionAttribute = nullptr;
	Qt3DRender::QAttribute* m_indexAttribute = nullptr;
	Qt3DRender::QAttribute* m_normalAttribute = nullptr;
	Qt3DRender::QBuffer* m_vertexBuffer = nullptr;
	Qt3DRender::QBuffer* m_indexBuffer = nullptr;

	QSharedPointer<PerlinNoiseElevationProvider> m_perlinNoiseElevationProvider;

	float m_radius = 1.0f;
	unsigned int m_subdivisions = 0;
};

#endif	// GEOSPHEREGEOMETRY_H
