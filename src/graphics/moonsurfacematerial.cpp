//
//  moonsurfacematerial.cpp
//  Saggat
//
//  Created by philipp on 07.11.2018.
//  Copyright (c) 2018 Philipp Engelhard. All rights reserved.
//
#include "moonsurfacematerial.h"
#include <Qt3DRender/QFilterKey>
#include <Qt3DRender/QGraphicsApiFilter>
#include <Qt3DRender/QMaterial>
#include <Qt3DRender/QEffect>
#include <Qt3DRender/QTechnique>
#include <Qt3DRender/QShaderProgram>
#include <Qt3DRender/QShaderProgramBuilder>
#include <Qt3DRender/QParameter>
#include <Qt3DRender/QRenderPass>
#include <Qt3DRender/QRenderPassFilter>
#include <QtCore/QUrl>
#include <QtGui/QVector3D>
#include <QtGui/QVector4D>

using namespace Qt3DRender;

namespace Saggat {

MoonSurfaceMaterial::MoonSurfaceMaterial(Qt3DCore::QNode* parent)
	: QMaterial(parent)
	, m_moonSurfaceEffect(new QEffect())
	, m_moonSurfaceGL3Technique(new QTechnique())
	, m_moonSurfaceGL2Technique(new QTechnique())
	, m_moonSurfaceES2Technique(new QTechnique())
	, m_moonSurfaceGL3RenderPass(new QRenderPass())
	, m_moonSurfaceGL2RenderPass(new QRenderPass())
	, m_moonSurfaceES2RenderPass(new QRenderPass())
	, m_moonSurfaceGL3Shader(new QShaderProgram())
	, m_moonSurfaceGL3ShaderBuilder(new QShaderProgramBuilder())
	, m_moonSurfaceGL2ES2Shader(new QShaderProgram())
	, m_moonSurfaceGL2ES2ShaderBuilder(new QShaderProgramBuilder())
	, m_filterKey(new QFilterKey)
{
	this->init();
}

MoonSurfaceMaterial::~MoonSurfaceMaterial()
{
}

void MoonSurfaceMaterial::init()
{

	m_moonSurfaceGL3Shader->setVertexShaderCode(QShaderProgram::loadSource(QUrl(QStringLiteral("qrc:/shaders/gl3/moonSurfaceShader.vert"))));
	m_moonSurfaceGL3Shader->setFragmentShaderCode(QShaderProgram::loadSource(QUrl(QStringLiteral("qrc:/shaders/gl3/moonSurfaceShader.frag"))));
	m_moonSurfaceGL3ShaderBuilder->setParent(this);
	m_moonSurfaceGL3ShaderBuilder->setShaderProgram(m_moonSurfaceGL3Shader);
//	m_moonSurfaceGL3ShaderBuilder->setFragmentShaderGraph(QUrl(QStringLiteral("qrc:/shaders/graphs/phong.frag.json")));
	m_moonSurfaceGL3ShaderBuilder->setEnabledLayers({QStringLiteral("diffuse"),
											   QStringLiteral("specular"),
											   QStringLiteral("normal")});

	m_moonSurfaceGL2ES2Shader->setVertexShaderCode(QShaderProgram::loadSource(QUrl(QStringLiteral("qrc:/shaders/es2/moonSurfaceShader.vert"))));
	m_moonSurfaceGL2ES2ShaderBuilder->setParent(this);
	m_moonSurfaceGL2ES2ShaderBuilder->setShaderProgram(m_moonSurfaceGL2ES2Shader);
	m_moonSurfaceGL2ES2ShaderBuilder->setFragmentShaderGraph(QUrl(QStringLiteral("qrc:/shaders/graphs/phong.frag.json")));
	m_moonSurfaceGL2ES2ShaderBuilder->setEnabledLayers({QStringLiteral("diffuse"),
												  QStringLiteral("specular"),
												  QStringLiteral("normal")});

	m_moonSurfaceGL3Technique->graphicsApiFilter()->setApi(QGraphicsApiFilter::OpenGL);
	m_moonSurfaceGL3Technique->graphicsApiFilter()->setMajorVersion(3);
	m_moonSurfaceGL3Technique->graphicsApiFilter()->setMinorVersion(1);
	m_moonSurfaceGL3Technique->graphicsApiFilter()->setProfile(QGraphicsApiFilter::CoreProfile);

	m_moonSurfaceGL2Technique->graphicsApiFilter()->setApi(QGraphicsApiFilter::OpenGL);
	m_moonSurfaceGL2Technique->graphicsApiFilter()->setMajorVersion(2);
	m_moonSurfaceGL2Technique->graphicsApiFilter()->setMinorVersion(0);
	m_moonSurfaceGL2Technique->graphicsApiFilter()->setProfile(QGraphicsApiFilter::NoProfile);

	m_moonSurfaceES2Technique->graphicsApiFilter()->setApi(QGraphicsApiFilter::OpenGLES);
	m_moonSurfaceES2Technique->graphicsApiFilter()->setMajorVersion(2);
	m_moonSurfaceES2Technique->graphicsApiFilter()->setMinorVersion(0);
	m_moonSurfaceES2Technique->graphicsApiFilter()->setProfile(QGraphicsApiFilter::NoProfile);

	m_moonSurfaceGL3RenderPass->setShaderProgram(m_moonSurfaceGL3Shader);
	m_moonSurfaceGL2RenderPass->setShaderProgram(m_moonSurfaceGL2ES2Shader);
	m_moonSurfaceES2RenderPass->setShaderProgram(m_moonSurfaceGL2ES2Shader);

	m_moonSurfaceGL3Technique->addRenderPass(m_moonSurfaceGL3RenderPass);
	m_moonSurfaceGL2Technique->addRenderPass(m_moonSurfaceGL2RenderPass);
	m_moonSurfaceES2Technique->addRenderPass(m_moonSurfaceES2RenderPass);

	m_filterKey->setParent(this);
	m_filterKey->setName(QStringLiteral("renderingStyle"));
	m_filterKey->setValue(QStringLiteral("forward"));

	m_moonSurfaceGL3Technique->addFilterKey(m_filterKey);
	m_moonSurfaceGL2Technique->addFilterKey(m_filterKey);
	m_moonSurfaceES2Technique->addFilterKey(m_filterKey);

	m_moonSurfaceEffect->addTechnique(m_moonSurfaceGL3Technique);
	m_moonSurfaceEffect->addTechnique(m_moonSurfaceGL2Technique);
	m_moonSurfaceEffect->addTechnique(m_moonSurfaceES2Technique);

//	m_moonSurfaceEffect->addParameter(m_ambientParameter);
//	m_moonSurfaceEffect->addParameter(m_diffuseParameter);
//	m_moonSurfaceEffect->addParameter(m_specularParameter);
//	m_moonSurfaceEffect->addParameter(m_shininessParameter);

	this->setEffect(m_moonSurfaceEffect);
}

} // namespace Saggat
