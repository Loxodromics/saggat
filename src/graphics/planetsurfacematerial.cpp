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
	, m_planetSurfaceGL2Technique(new QTechnique())
	, m_planetSurfaceES2Technique(new QTechnique())
	, m_planetSurfaceGL3RenderPass(new QRenderPass())
	, m_planetSurfaceGL2RenderPass(new QRenderPass())
	, m_planetSurfaceES2RenderPass(new QRenderPass())
	, m_planetSurfaceGL3Shader(new QShaderProgram())
	, m_planetSurfaceGL3ShaderBuilder(new QShaderProgramBuilder())
	, m_planetSurfaceGL2ES2Shader(new QShaderProgram())
	, m_planetSurfaceGL2ES2ShaderBuilder(new QShaderProgramBuilder())
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

	m_planetSurfaceGL2ES2Shader->setVertexShaderCode(QShaderProgram::loadSource(QUrl(QStringLiteral("qrc:/shaders/es2/planetSurfaceShader.vert"))));
	m_planetSurfaceGL2ES2ShaderBuilder->setParent(this);
	m_planetSurfaceGL2ES2ShaderBuilder->setShaderProgram(m_planetSurfaceGL2ES2Shader);
	m_planetSurfaceGL2ES2ShaderBuilder->setFragmentShaderGraph(QUrl(QStringLiteral("qrc:/shaders/graphs/phong.frag.json")));
	m_planetSurfaceGL2ES2ShaderBuilder->setEnabledLayers({QStringLiteral("diffuse"),
												  QStringLiteral("specular"),
												  QStringLiteral("normal")});

	m_planetSurfaceGL3Technique->graphicsApiFilter()->setApi(QGraphicsApiFilter::OpenGL);
	m_planetSurfaceGL3Technique->graphicsApiFilter()->setMajorVersion(3);
	m_planetSurfaceGL3Technique->graphicsApiFilter()->setMinorVersion(1);
	m_planetSurfaceGL3Technique->graphicsApiFilter()->setProfile(QGraphicsApiFilter::CoreProfile);

	m_planetSurfaceGL2Technique->graphicsApiFilter()->setApi(QGraphicsApiFilter::OpenGL);
	m_planetSurfaceGL2Technique->graphicsApiFilter()->setMajorVersion(2);
	m_planetSurfaceGL2Technique->graphicsApiFilter()->setMinorVersion(0);
	m_planetSurfaceGL2Technique->graphicsApiFilter()->setProfile(QGraphicsApiFilter::NoProfile);

	m_planetSurfaceES2Technique->graphicsApiFilter()->setApi(QGraphicsApiFilter::OpenGLES);
	m_planetSurfaceES2Technique->graphicsApiFilter()->setMajorVersion(2);
	m_planetSurfaceES2Technique->graphicsApiFilter()->setMinorVersion(0);
	m_planetSurfaceES2Technique->graphicsApiFilter()->setProfile(QGraphicsApiFilter::NoProfile);

	m_planetSurfaceGL3RenderPass->setShaderProgram(m_planetSurfaceGL3Shader);
	m_planetSurfaceGL2RenderPass->setShaderProgram(m_planetSurfaceGL2ES2Shader);
	m_planetSurfaceES2RenderPass->setShaderProgram(m_planetSurfaceGL2ES2Shader);

	m_planetSurfaceGL3Technique->addRenderPass(m_planetSurfaceGL3RenderPass);
	m_planetSurfaceGL2Technique->addRenderPass(m_planetSurfaceGL2RenderPass);
	m_planetSurfaceES2Technique->addRenderPass(m_planetSurfaceES2RenderPass);

	m_filterKey->setParent(this);
	m_filterKey->setName(QStringLiteral("renderingStyle"));
	m_filterKey->setValue(QStringLiteral("forward"));

	m_planetSurfaceGL3Technique->addFilterKey(m_filterKey);
	m_planetSurfaceGL2Technique->addFilterKey(m_filterKey);
	m_planetSurfaceES2Technique->addFilterKey(m_filterKey);

	m_planetSurfaceEffect->addTechnique(m_planetSurfaceGL3Technique);
	m_planetSurfaceEffect->addTechnique(m_planetSurfaceGL2Technique);
	m_planetSurfaceEffect->addTechnique(m_planetSurfaceES2Technique);

//	m_planetSurfaceEffect->addParameter(m_ambientParameter);
//	m_planetSurfaceEffect->addParameter(m_diffuseParameter);
//	m_planetSurfaceEffect->addParameter(m_specularParameter);
//	m_planetSurfaceEffect->addParameter(m_shininessParameter);

	this->setEffect(m_planetSurfaceEffect);
}

} // namespace Saggat
