//
//  planetsurfacematerial.cpp
//  Saggat
//
//  Created by philipp2 on 02.11.2018.
//  Copyright (c) 2018 Philipp Engelhard. All rights reserved.
//
#include "planetsurfacematerial.h"
//#include <Qt3DRender/qfilterkey.h>
#include <Qt3DRender/QFilterKey>
#include <Qt3DRender/QGraphicsApiFilter>
//#include <Qt3DRender/qmaterial.h>
#include <Qt3DRender/QMaterial>
//#include <Qt3DRender/qeffect.h>
#include <Qt3DRender/QEffect>
//#include <Qt3DRender/qtechnique.h>
#include <Qt3DRender/QTechnique>
//#include <Qt3DRender/qshaderprogram.h>
#include <Qt3DRender/QShaderProgram>
//#include <Qt3DRender/qshaderprogrambuilder.h>
#include <Qt3DRender/QShaderProgramBuilder>
//#include <Qt3DRender/qparameter.h>
#include <Qt3DRender/QParameter>
//#include <Qt3DRender/qrenderpass.h>
#include <Qt3DRender/QRenderPass>
//#include <Qt3DRender/qgraphicsapifilter.h>
#include <Qt3DRender/QRenderPassFilter>
#include <QtCore/QUrl>
#include <QtGui/QVector3D>
#include <QtGui/QVector4D>

using namespace Qt3DRender;

namespace Saggat {

PlanetSurfaceMaterial::PlanetSurfaceMaterial(Qt3DCore::QNode* parent)
	: QMaterial(parent)
	, m_planetSurfaceEffect(new QEffect())
	, m_planetSurfaceGL3Technique(new QTechnique())
	, m_planetSurfaceES3Technique(new QTechnique())
	, m_planetSurfaceGL3RenderPass(new QRenderPass())
	, m_planetSurfaceES3RenderPass(new QRenderPass())
	, m_planetSurfaceGL3Shader(new QShaderProgram())
	, m_planetSurfaceGL3ShaderBuilder(new QShaderProgramBuilder())
	, m_planetSurfaceES3Shader(new QShaderProgram())
	, m_planetSurfaceES3ShaderBuilder(new QShaderProgramBuilder())
	, m_filterKey(new QFilterKey)
{
	this->init();
}

PlanetSurfaceMaterial::~PlanetSurfaceMaterial()
{
}

void PlanetSurfaceMaterial::init()
{

	m_planetSurfaceGL3Shader->setVertexShaderCode(QShaderProgram::loadSource(QUrl(QStringLiteral("qrc:/shaders/gl3/planetSurfaceShader.vert"))));
	m_planetSurfaceGL3Shader->setFragmentShaderCode(QShaderProgram::loadSource(QUrl(QStringLiteral("qrc:/shaders/gl3/planetSurfaceShader.frag"))));
	m_planetSurfaceGL3ShaderBuilder->setParent(this);
	m_planetSurfaceGL3ShaderBuilder->setShaderProgram(m_planetSurfaceGL3Shader);
//	m_planetSurfaceGL3ShaderBuilder->setFragmentShaderGraph(QUrl(QStringLiteral("qrc:/shaders/graphs/phong.frag.json")));
	m_planetSurfaceGL3ShaderBuilder->setEnabledLayers({QStringLiteral("diffuse"),
											   QStringLiteral("specular"),
											   QStringLiteral("normal")});

	m_planetSurfaceES3Shader->setVertexShaderCode(QShaderProgram::loadSource(QUrl(QStringLiteral("qrc:/shaders/es3/planetSurfaceShader.vert"))));
	m_planetSurfaceES3Shader->setFragmentShaderCode(QShaderProgram::loadSource(QUrl(QStringLiteral("qrc:/shaders/es3/planetSurfaceShader.frag"))));
	m_planetSurfaceES3ShaderBuilder->setParent(this);
	m_planetSurfaceES3ShaderBuilder->setShaderProgram(m_planetSurfaceES3Shader);
//	m_planetSurfaceES3ShaderBuilder->setFragmentShaderGraph(QUrl(QStringLiteral("qrc:/shaders/es3/planetSurfaceShader.frag")));
	m_planetSurfaceES3ShaderBuilder->setEnabledLayers({QStringLiteral("diffuse"),
												  QStringLiteral("specular"),
												  QStringLiteral("normal")});

	m_planetSurfaceGL3Technique->graphicsApiFilter()->setApi(QGraphicsApiFilter::OpenGL);
	m_planetSurfaceGL3Technique->graphicsApiFilter()->setMajorVersion(3);
	m_planetSurfaceGL3Technique->graphicsApiFilter()->setMinorVersion(1);
	m_planetSurfaceGL3Technique->graphicsApiFilter()->setProfile(QGraphicsApiFilter::CoreProfile);

	m_planetSurfaceES3Technique->graphicsApiFilter()->setApi(QGraphicsApiFilter::OpenGLES);
	m_planetSurfaceES3Technique->graphicsApiFilter()->setMajorVersion(3);
	m_planetSurfaceES3Technique->graphicsApiFilter()->setMinorVersion(0);
	m_planetSurfaceES3Technique->graphicsApiFilter()->setProfile(QGraphicsApiFilter::NoProfile);

	m_planetSurfaceGL3RenderPass->setShaderProgram(m_planetSurfaceGL3Shader);
	m_planetSurfaceES3RenderPass->setShaderProgram(m_planetSurfaceES3Shader);

	m_planetSurfaceGL3Technique->addRenderPass(m_planetSurfaceGL3RenderPass);
	m_planetSurfaceES3Technique->addRenderPass(m_planetSurfaceES3RenderPass);

	m_filterKey->setParent(this);
	m_filterKey->setName(QStringLiteral("renderingStyle"));
	m_filterKey->setValue(QStringLiteral("forward"));

	m_planetSurfaceGL3Technique->addFilterKey(m_filterKey);
	m_planetSurfaceES3Technique->addFilterKey(m_filterKey);

	m_planetSurfaceEffect->addTechnique(m_planetSurfaceGL3Technique);
	m_planetSurfaceEffect->addTechnique(m_planetSurfaceES3Technique);

//	m_planetSurfaceEffect->addParameter(m_ambientParameter);
//	m_planetSurfaceEffect->addParameter(m_diffuseParameter);
//	m_planetSurfaceEffect->addParameter(m_specularParameter);
//	m_planetSurfaceEffect->addParameter(m_shininessParameter);

	this->setEffect(m_planetSurfaceEffect);
}

} // namespace Saggat
