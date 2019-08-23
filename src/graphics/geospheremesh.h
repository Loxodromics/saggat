//
//  geospheremesh.h
//  Qt3D-Geosphere
//
//  Created by philipp on 08.08.2019.
//  Copyright (c) 2019 Philipp Engelhard. All rights reserved.
//
#ifndef GEOSPHEREMESH_H
#define GEOSPHEREMESH_H

#include <Qt3DExtras/qt3dextras_global.h>
#include <Qt3DRender/qgeometryrenderer.h>

class GeosphereMesh : public Qt3DRender::QGeometryRenderer {

	Q_OBJECT

	Q_PROPERTY(float radius READ radius WRITE setRadius NOTIFY radiusChanged)
	Q_PROPERTY(unsigned int subdivisions READ subdivisions WRITE setSubdivisions NOTIFY subdivisionsChanged)

public:
	explicit GeosphereMesh(Qt3DCore::QNode* parent = nullptr);
	~GeosphereMesh();

	float radius() const;

	unsigned int subdivisions() const;

public slots:
	void setRadius(float radius);
	void setSubdivisions(unsigned int subdivisions);

signals:
	void radiusChanged(float radius);
	void subdivisionsChanged(unsigned int subdivisions);

protected:
	// As this is a default provided geometry renderer, no one should be able
	// to modify the QGeometryRenderer's properties

	void setInstanceCount(int instanceCount);
	void setVertexCount(int vertexCount);
	void setIndexOffset(int indexOffset);
	void setFirstInstance(int firstInstance);
	void setRestartIndexValue(int index);
	void setPrimitiveRestartEnabled(bool enabled);
	void setGeometry(Qt3DRender::QGeometry* geometry);
	void setPrimitiveType(PrimitiveType primitiveType);
};

#endif	// GEOSPHEREMESH_H
