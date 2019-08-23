//
//  geospheremesh.cpp
//  Qt3D-Geosphere
//
//  Created by philipp on 08.08.2019.
//  Copyright (c) 2019 Philipp Engelhard. All rights reserved.
//
#include "geospheremesh.h"
#include "geospheregeometry.h"

GeosphereMesh::GeosphereMesh(QNode* parent)
	: QGeometryRenderer(parent)
{
	GeosphereGeometry* geometry = new GeosphereGeometry(this);
	QGeometryRenderer::setGeometry(geometry);
	QGeometryRenderer::setPrimitiveType(Qt3DRender::QGeometryRenderer::Triangles);

	QObject::connect(geometry, &GeosphereGeometry::radiusChanged, this, &GeosphereMesh::radiusChanged);
	QObject::connect(geometry, &GeosphereGeometry::subdivisionsChanged, this, &GeosphereMesh::subdivisionsChanged);
}

GeosphereMesh::~GeosphereMesh() {}

float GeosphereMesh::radius() const { return static_cast<GeosphereGeometry*>(geometry())->radius(); }

unsigned int GeosphereMesh::subdivisions() const { return static_cast<GeosphereGeometry*>(geometry())->subdivisions(); }

void GeosphereMesh::setRadius(float radius) { static_cast<GeosphereGeometry*>(geometry())->setRadius(radius); }

void GeosphereMesh::setSubdivisions(unsigned int subdivisions)
{
	static_cast<GeosphereGeometry*>(geometry())->setSubdivisions(subdivisions);
}
