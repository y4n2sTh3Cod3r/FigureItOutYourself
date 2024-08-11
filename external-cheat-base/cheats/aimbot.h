#pragma once

#include "../SDK/client.h"
#include "../SDK/offsets.h"

#include "../math/vector.h"
#include "../memory/memory.h"

namespace aimbot
{
	inline uintptr_t module_base;
	inline uintptr_t procID;

	float distance(vec3 p1, vec3 p2);
	void frame();
}
