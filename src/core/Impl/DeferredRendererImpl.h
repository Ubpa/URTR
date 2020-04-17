#pragma once

#include <URTR/DeferredRenderer.h>

#include <UGL/UGL.h>

#include <map>
#include <string>

namespace Ubpa {
	class Primitive;
	class Texture2D;

	class DeferredRenderer::Impl {
	public:
		Impl();
		~Impl();

		void RenderImpl(Scene* scene, SObj* camObj, size_t width, size_t height);

	private:
		void ResizeBuffer(size_t width, size_t height);
		gl::Mesh* GetPrimitiveMesh(const Primitive* primitive);
		enum class DefaultTex {
			White,
			Normal,
		};
		enum class TexPrecision {
			Byte8,
			F16,
			F32
		};
		gl::Texture2D* GetGLTex2D(const Texture2D* img, DefaultTex default_tex = DefaultTex::White, TexPrecision precision = TexPrecision::Byte8);

	private:
		std::map<const Primitive*, gl::Mesh*> primitive2mesh;
		size_t width{ 0 };
		size_t height{ 0 };

		std::array<gl::Texture2D*, 4> gtexs{ nullptr };
		gl::RenderBuffer* depth{ nullptr };
		gl::Program* gProgram{ nullptr };
		gl::Program* deferredlightProgram{ nullptr };
		gl::Program* envProgram{ nullptr };
		gl::Program* screenProgram{ nullptr };
		gl::FrameBuffer gb;

		gl::Texture2D* lightingBuffer_tex;
		gl::FrameBuffer lightingBuffer;

		gl::Mesh* screen{ nullptr };
		gl::Mesh* sphere{ nullptr };
		gl::Mesh* cube{ nullptr };

		gl::Texture2D default_white;
		gl::Texture2D default_normal;
	};
}
