//
//  planetsurfacematerial.h
//  Saggat
//
//  Created by philipp2 on 02.11.2018.
//  Copyright (c) 2018 Philipp Engelhard. All rights reserved.
//
#ifndef SAGGAT_PLANETSURFACEMATERIAL_H
#define SAGGAT_PLANETSURFACEMATERIAL_H

#include <Qt3DExtras/qt3dextras_global.h>
//#include <Qt3DRender/qmaterial.h>
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

//namespace Qt3DRender {

//class QFilterKey;
//class QEffect;
//class QTechnique;
//class QParameter;
//class QShaderProgram;
//class QShaderProgramBuilder;
//class QRenderPass;

//} // namespace Qt3DRender

namespace Saggat {

class QT3DRENDERSHARED_EXPORT PlanetSurfaceMaterial : public Qt3DRender::QMaterial
{
	Q_OBJECT

public:
	PlanetSurfaceMaterial(Qt3DCore::QNode* parent = nullptr);
	~PlanetSurfaceMaterial();

	void init();

protected:
	Qt3DRender::QEffect *m_planetSurfaceEffect;
	Qt3DRender::QParameter *m_ambientParameter;
	Qt3DRender::QParameter *m_diffuseParameter;
	Qt3DRender::QParameter *m_specularParameter;
	Qt3DRender::QParameter *m_shininessParameter;
	Qt3DRender::QTechnique *m_planetSurfaceGL3Technique;
	Qt3DRender::QTechnique *m_planetSurfaceGL2Technique;
	Qt3DRender::QTechnique *m_planetSurfaceES2Technique;
	Qt3DRender::QRenderPass *m_planetSurfaceGL3RenderPass;
	Qt3DRender::QRenderPass *m_planetSurfaceGL2RenderPass;
	Qt3DRender::QRenderPass *m_planetSurfaceES2RenderPass;
	Qt3DRender::QShaderProgram *m_planetSurfaceGL3Shader;
	Qt3DRender::QShaderProgramBuilder *m_planetSurfaceGL3ShaderBuilder;
	Qt3DRender::QShaderProgram *m_planetSurfaceGL2ES2Shader;
	Qt3DRender::QShaderProgramBuilder *m_planetSurfaceGL2ES2ShaderBuilder;
	Qt3DRender::QFilterKey *m_filterKey;
};

} // namespace Saggat

#endif // SAGGAT_PLANETSURFACEMATERIAL_H
