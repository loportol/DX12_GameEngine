#pragma once

//Library Header Files
#include <Windows.h>




#include "EngineMin.h"

//Wrapper for Engine Window
namespace Engine {

	class KT_API Application
	{
	public:
		//Default constructor
		//We don't care about the creation
		Application() = default;

		bool Initialize();

		void Update();

		inline bool isRunning() { return m_isRunning; }

	private:
		HWND m_WindowHandle = nullptr;

		bool m_isRunning = false;
	};
}


