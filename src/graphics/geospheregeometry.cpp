//
//  geospheregeometry.cpp
//  Qt3D-Geosphere
//
//  Created by philipp on 08.08.2019.
//  Copyright (c) 2019 Philipp Engelhard. All rights reserved.
//
#include "geospheregeometry.h"
#include "src/generation/perlinnoiseelevationprovider.h"
#include "src/generation/simplexnoiseelevationprovider.h"

#include <QVector3D>
#include <Qt3DRender/QAttribute>
#include <Qt3DRender/QBufferDataGenerator>
#include <Qt3DRender/qbuffer.h>

#include <QDebug>

#include <array>
#include <limits>
#include <stdlib.h>

#include "src/common/values.h"

using Index = uint64_t;
using Triangle = std::array<Index, 3>;
using TriangleList = std::vector<Triangle>;
using VertexList = std::vector<QVector3D>;
using Lookup = std::map<std::pair<Index, Index>, Index>;
using IndexedMesh = std::pair<VertexList, TriangleList>;

using namespace Qt3DRender;

namespace {

Index vertexForEdge(Lookup& lookup, VertexList& vertices, Index first, Index second)
{
	Lookup::key_type key(first, second);
	if (key.first > key.second)
		std::swap(key.first, key.second);

	auto inserted = lookup.insert({ key, vertices.size() });
	if (inserted.second) {
		auto& edge0 = vertices[first];
		auto& edge1 = vertices[second];
		auto point = (edge0 + edge1).normalized();
		vertices.push_back(point);
	}

	return inserted.first->second;
}

TriangleList subdivide(VertexList& vertices, TriangleList triangles)
{
	Lookup lookup;
	TriangleList result;

	for (auto&& each : triangles) {
		std::array<Index, 3> mid;
		for (unsigned long edge = 0; edge < 3; ++edge) {
			mid[edge] = vertexForEdge(lookup, vertices, each[edge], each[(edge + 1) % 3]);
		}

		result.push_back({ each[0], mid[0], mid[2] });
		result.push_back({ each[1], mid[1], mid[0] });
		result.push_back({ each[2], mid[2], mid[1] });
		result.push_back({ mid[0], mid[1], mid[2] });
	}

	return result;
}

IndexedMesh makeGeoSphere(unsigned int subdivisions)
{
	const float X = 0.525731112119133606f;
	const float Z = 0.850650808352039932f;

	/// Vertices
	VertexList vertices
	  = { QVector3D(-X, 0.0f, Z), QVector3D(X, 0.0f, Z), QVector3D(-X, 0.0f, -Z), QVector3D(X, 0.0f, -Z),
			QVector3D(0.0f, Z, X), QVector3D(0.0f, Z, -X), QVector3D(0.0f, -Z, X), QVector3D(0.0f, -Z, -X),
			QVector3D(Z, X, 0.0f), QVector3D(-Z, X, 0.0f), QVector3D(Z, -X, 0.0f), QVector3D(-Z, -X, 0.0f) };

	// clang-format off
	TriangleList triangles = { {1, 4, 0},
							   {4, 9, 0},
							   {4, 5, 9},
							   {8, 5, 4},
							   {1, 8, 4},
							   {1, 10, 8},
							   {10, 3, 8},
							   {8, 3, 5},
							   {3, 2, 5},
							   {3, 7, 2},
							   {3, 10, 7},
							   {10, 6, 7},
							   {6, 11, 7},
							   {6, 0, 11},
							   {6, 1, 0},
							   {10, 1, 6},
							   {11, 0, 9},
							   {2, 11, 9},
							   {5, 2, 9},
							   {11, 2, 7} };
	// clang-format on

	for (unsigned int i = 0; i < subdivisions; ++i) {
		triangles = subdivide(vertices, triangles);
	}

	return { vertices, triangles };
}

QByteArray createGeosphereMeshVertexData(VertexList vertices, float radius, QSharedPointer<ElevationProvider> elevationProvider)
{
	QByteArray bufferBytes;
	/// vec3 pos and vec3 normal
	const quint32 elementSize = 3 + 3;
	const quint32 stride = elementSize * sizeof(float);
	const unsigned long nVerts = vertices.size();
	bufferBytes.resize(static_cast<int>(stride * nVerts));

	float* fptr = reinterpret_cast<float*>(bufferBytes.data());

	for (auto vertex : vertices) {
		float elevation = 1.0f;
		if (!elevationProvider.isNull())
		{
			elevation = static_cast<float>(elevationProvider->elevationAt(static_cast<double>(vertex.x()),
																		  static_cast<double>(vertex.y()),
																		  static_cast<double>(vertex.z())));
			elevation *= static_cast<float>(Saggat::Values::getInstance().terrainHeightFactor());
			elevation += 1.0f;
		}
		*fptr++ = vertex.x() * radius * elevation;
		*fptr++ = vertex.y() * radius * elevation;
		*fptr++ = vertex.z() * radius * elevation;

		auto normal = vertex.normalized();
		*fptr++ = normal.x();
		*fptr++ = normal.y();
		*fptr++ = normal.z();
	}
	return bufferBytes;
}

QByteArray createGeosphereMeshIndexData(TriangleList triangles)
{
	const unsigned long faces = triangles.size();

	QByteArray indexBytes;
	const unsigned long indices = faces * 3;
	Q_ASSERT(indices < INT_MAX);
	indexBytes.resize(static_cast<int>(indices * sizeof(quint16)));
	quint16* indexPtr = reinterpret_cast<quint16*>(indexBytes.data());

	for (const auto each : triangles) {
		*indexPtr++ = static_cast<quint16>(each[0]);
		*indexPtr++ = static_cast<quint16>(each[1]);
		*indexPtr++ = static_cast<quint16>(each[2]);
	}

	return indexBytes;
}

}	// anonymous

class GeosphereVertexDataFunctor : public Qt3DRender::QBufferDataGenerator {
public:
	GeosphereVertexDataFunctor(VertexList vertices, float radius, QSharedPointer<ElevationProvider> elevationProvider)
		: m_vertices(vertices)
		, m_radius(radius)
		, m_elevationProvider(elevationProvider)
	{
	}

	QByteArray operator()() override { return createGeosphereMeshVertexData(this->m_vertices, this->m_radius, this->m_elevationProvider); }

	bool operator==(const QBufferDataGenerator& other) const override
	{
		const GeosphereVertexDataFunctor* otherFunctor = functor_cast<GeosphereVertexDataFunctor>(&other);
		if (otherFunctor != nullptr)
			return (otherFunctor->m_vertices == this->m_vertices &&
					qFuzzyCompare(otherFunctor->m_radius, this->m_radius) &&
					otherFunctor->m_elevationProvider.get() == this->m_elevationProvider.get());
		return false;
	}

	QT3D_FUNCTOR(GeosphereVertexDataFunctor)

private:
	VertexList m_vertices;
	float m_radius;
	QSharedPointer<ElevationProvider> m_elevationProvider;
};

class GeosphereIndexDataFunctor : public QBufferDataGenerator {
public:
	GeosphereIndexDataFunctor(TriangleList triangles)
		: m_triangles(triangles)
	{
	}

	QByteArray operator()() override { return createGeosphereMeshIndexData(this->m_triangles); }

	bool operator==(const QBufferDataGenerator& other) const override
	{
		const GeosphereIndexDataFunctor* otherFunctor = functor_cast<GeosphereIndexDataFunctor>(&other);
		if (otherFunctor != nullptr)
			return (otherFunctor->m_triangles == this->m_triangles);
		return false;
	}

	QT3D_FUNCTOR(GeosphereIndexDataFunctor)

private:
	TriangleList m_triangles;
};

GeosphereGeometry::GeosphereGeometry(Qt3DCore::QNode* parent)
	: Qt3DRender::QGeometry(parent)
	, m_positionAttribute(nullptr)
	, m_indexAttribute(nullptr)
	, m_normalAttribute(nullptr)
	, m_vertexBuffer(nullptr)
	, m_indexBuffer(nullptr)
	, m_elevationProvider(QSharedPointer<Saggat::SimplexNoiseElevationProvider>::create(Saggat::Values::getInstance().terrainSeed(), Saggat::Values::getInstance().terrainOctaves()))
{
	this->init();
}

GeosphereGeometry::~GeosphereGeometry() {}

QAttribute* GeosphereGeometry::positionAttribute() const { return this->m_positionAttribute; }

QAttribute* GeosphereGeometry::indexAttribute() const { return this->m_indexAttribute; }

QAttribute* GeosphereGeometry::normalAttribute() const { return this->m_normalAttribute; }

float GeosphereGeometry::radius() const { return this->m_radius; }

unsigned int GeosphereGeometry::subdivisions() const { return this->m_subdivisions; }

void GeosphereGeometry::setRadius(float radius)
{
	if (qFuzzyCompare(this->m_radius, radius))
		return;

	this->m_radius = radius;
	this->update();
	emit radiusChanged(this->m_radius);
}

void GeosphereGeometry::setSubdivisions(unsigned int subdivisions)
{
	if (this->m_subdivisions == subdivisions)
		return;

	this->m_subdivisions = subdivisions;
	this->update();
	emit subdivisionsChanged(this->m_subdivisions);
}

void GeosphereGeometry::init()
{
	this->m_positionAttribute = new QAttribute(this);
	this->m_indexAttribute = new QAttribute(this);
	this->m_normalAttribute = new QAttribute(this);
	this->m_vertexBuffer = new Qt3DRender::QBuffer(this);
	this->m_indexBuffer = new Qt3DRender::QBuffer(this);

	auto verticesTriangles = makeGeoSphere(this->m_subdivisions);

	const uint nVerts = static_cast<uint>(verticesTriangles.second.size() * 3);

	/// vec3 pos, vec3 normal
	const int stride = (3 + 3) * sizeof(float);

	this->m_positionAttribute->setName(QAttribute::defaultPositionAttributeName());
	this->m_positionAttribute->setVertexBaseType(QAttribute::Float);
	this->m_positionAttribute->setVertexSize(3);
	this->m_positionAttribute->setAttributeType(QAttribute::VertexAttribute);
	this->m_positionAttribute->setBuffer(this->m_vertexBuffer);
	this->m_positionAttribute->setByteStride(stride);
	this->m_positionAttribute->setCount(nVerts);

	this->m_normalAttribute->setName(QAttribute::defaultNormalAttributeName());
	this->m_normalAttribute->setVertexBaseType(QAttribute::Float);
	this->m_normalAttribute->setVertexSize(3);
	this->m_normalAttribute->setAttributeType(QAttribute::VertexAttribute);
	this->m_normalAttribute->setBuffer(this->m_vertexBuffer);
	this->m_normalAttribute->setByteStride(stride);
	this->m_normalAttribute->setByteOffset(3 * sizeof(float));
	this->m_normalAttribute->setCount(nVerts);

	this->m_indexAttribute->setAttributeType(QAttribute::IndexAttribute);
	this->m_indexAttribute->setVertexBaseType(QAttribute::UnsignedShort);
	this->m_indexAttribute->setBuffer(this->m_indexBuffer);
	this->m_indexAttribute->setCount(nVerts);

	this->m_vertexBuffer->setDataGenerator(
	  QSharedPointer<GeosphereVertexDataFunctor>::create(verticesTriangles.first, this->m_radius, this->m_elevationProvider));
	this->m_indexBuffer->setDataGenerator(QSharedPointer<GeosphereIndexDataFunctor>::create(verticesTriangles.second));

	this->addAttribute(this->m_positionAttribute);
	this->addAttribute(this->m_normalAttribute);
	this->addAttribute(this->m_indexAttribute);
}

void GeosphereGeometry::update()
{
	///FIXME: this is currently needed to regenerate geometry
	this->m_elevationProvider = QSharedPointer<Saggat::SimplexNoiseElevationProvider>::create(Saggat::Values::getInstance().terrainSeed(), Saggat::Values::getInstance().terrainOctaves());

	auto verticesTriangles = makeGeoSphere(this->m_subdivisions);

	const uint nVerts = static_cast<uint>(verticesTriangles.second.size() * 3);
	this->m_positionAttribute->setCount(nVerts);
	this->m_normalAttribute->setCount(nVerts);
	this->m_indexAttribute->setCount(nVerts);
	this->m_vertexBuffer->setDataGenerator(
	  QSharedPointer<GeosphereVertexDataFunctor>::create(verticesTriangles.first, this->m_radius, this->m_elevationProvider));
	this->m_indexBuffer->setDataGenerator(QSharedPointer<GeosphereIndexDataFunctor>::create(verticesTriangles.second));
}

QSharedPointer<ElevationProvider> GeosphereGeometry::elevationProvider() const
{
	return m_elevationProvider;
}

void GeosphereGeometry::setElevationProvider(const QSharedPointer<ElevationProvider>& elevationProvider)
{
	m_elevationProvider = elevationProvider;
}
