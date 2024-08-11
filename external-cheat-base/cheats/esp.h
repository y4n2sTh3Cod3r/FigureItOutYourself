#pragma once

#include <vector>

#include "../renderer/renderer.h"
#include "../SDK/client.h"
#include "../SDK/offsets.h"

struct viewMatrix
{
	float m[16];
};

namespace esp
{
	inline std::vector<uintptr_t> entities;
	inline viewMatrix vm = {};

	inline uintptr_t pID;
	inline uintptr_t modBase;

	void frame();
	void loop();
	void render();

	bool w2s(const vec3& world, vec2& screen, float m[16]);
}