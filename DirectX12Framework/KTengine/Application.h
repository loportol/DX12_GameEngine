#pragma once
#include "KTengineMin.h"

//Library Header Files
#include <Windows.h>

#include "RenderAPI.h"

//Wrapper for Engine Window
namespace KTengine {

	class KT_API Application
	{
	public:
		//Default constructor
		//We don't care about the creation
		Application() = default;

		bool Initialize();

		void OnCreate(HWND hwnd);

		void OnDestroy();

		void Update();

		inline bool isRunning() { return m_isRunning; }


	private: //subsystems
		RenderAPI m_Renderer;



	private: //variables
		HWND m_WindowHandle = nullptr;

		bool m_isRunning = false;
	};
}


