//
//  moonsurfacematerial.h
//  Saggat
//
//  Created by philipp on 07.11.2018.
//  Copyright (c) 2018 Philipp Engelhard. All rights reserved.
//
#ifndef SAGGAT_MOONSURFACEMATERIAL_H
#define SAGGAT_MOONSURFACEMATERIAL_H

#include <Qt3DExtras/qt3dextras_global.h>
#include <QtGui/QColor>

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

namespace Saggat {

class MoonSurfaceMaterial : public Qt3DRender::QMaterial
{
	Q_OBJECT

public:
	MoonSurfaceMaterial(Qt3DCore::QNode* parent = nullptr);
	~MoonSurfaceMaterial();

	void init();

protected:
	Qt3DRender::QEffect *m_moonSurfaceEffect;
	Qt3DRender::QParameter *m_ambientParameter;
	Qt3DRender::QParameter *m_diffuseParameter;
	Qt3DRender::QParameter *m_specularParameter;
	Qt3DRender::QParameter *m_shininessParameter;
	Qt3DRender::QTechnique *m_moonSurfaceGL3Technique;
	Qt3DRender::QTechnique *m_moonSurfaceGL2Technique;
	Qt3DRender::QTechnique *m_moonSurfaceES2Technique;
	Qt3DRender::QRenderPass *m_moonSurfaceGL3RenderPass;
	Qt3DRender::QRenderPass *m_moonSurfaceGL2RenderPass;
	Qt3DRender::QRenderPass *m_moonSurfaceES2RenderPass;
	Qt3DRender::QShaderProgram *m_moonSurfaceGL3Shader;
	Qt3DRender::QShaderProgramBuilder *m_moonSurfaceGL3ShaderBuilder;
	Qt3DRender::QShaderProgram *m_moonSurfaceGL2ES2Shader;
	Qt3DRender::QShaderProgramBuilder *m_moonSurfaceGL2ES2ShaderBuilder;
	Qt3DRender::QFilterKey *m_filterKey;
};

} // namespace Saggat

#endif // SAGGAT_MOONSURFACEMATERIAL_H
