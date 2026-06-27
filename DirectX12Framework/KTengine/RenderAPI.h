#pragma once
#include "KTengineMin.h"

#include <Windows.h>

namespace KTengine {
	class KT_API RenderAPI
	{


	public:
		RenderAPI() = default;

		~RenderAPI();

		void Initialize(HWND hwnd);

	};
}


