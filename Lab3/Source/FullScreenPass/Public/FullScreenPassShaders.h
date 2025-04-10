#pragma once
#include "CoreMinimal.h"
#include "ScreenPass.h"
#include "SceneTexturesConfig.h"

// Подключаемые шейдеры из .usf
#include "GlobalShader.h"
#include "ShaderParameterStruct.h"

class FFullScreenPassVS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FFullScreenPassVS);

	FFullScreenPassVS() = default;
	FFullScreenPassVS(const ShaderMetaType::CompiledShaderInitializerType& Initializer) : FGlobalShader(Initializer) {}
};

class FFullScreenPassPS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FFullScreenPassPS);
	SHADER_USE_PARAMETER_STRUCT(FFullScreenPassPS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		RENDER_TARGET_BINDING_SLOTS()
		SHADER_PARAMETER_STRUCT_REF(FViewUniformShaderParameters, View)
		SHADER_PARAMETER_RDG_UNIFORM_BUFFER(FSceneTextureUniformParameters, SceneTexturesStruct)

		// Параметры PandaFX
		SHADER_PARAMETER(float, Contrast_R)
		SHADER_PARAMETER(float, Contrast_G)
		SHADER_PARAMETER(float, Contrast_B)
		SHADER_PARAMETER(float, Gamma_R)
		SHADER_PARAMETER(float, Gamma_G)
		SHADER_PARAMETER(float, Gamma_B)
		SHADER_PARAMETER(float, Blend_Amount)
		SHADER_PARAMETER(float, Bleach_Bypass_Amount)
		SHADER_PARAMETER(float, Enable_Bleach_Bypass)

		SHADER_PARAMETER(float, Enable_Diffusion)
		SHADER_PARAMETER(float, Diffusion_1_Amount)
		SHADER_PARAMETER(float, Diffusion_1_Radius)
		SHADER_PARAMETER(float, Diffusion_1_Gamma)
		SHADER_PARAMETER(float, Diffusion_2_Amount)
		SHADER_PARAMETER(float, Diffusion_2_Radius)
		SHADER_PARAMETER(float, Diffusion_2_Gamma)
		SHADER_PARAMETER(float, Diffusion_3_Amount)
		SHADER_PARAMETER(float, Diffusion_3_Radius)
		SHADER_PARAMETER(float, Diffusion_3_Gamma)


	END_SHADER_PARAMETER_STRUCT()
};
