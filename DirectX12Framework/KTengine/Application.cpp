#include "pch.h"
#include "Application.h"

//Contains macros necessary for the project
#include <windowsx.h>
#include <iostream>

namespace Engine {

	//Define callback function
	LRESULT CALLBACK WindProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
		
		switch (msg) {
			case WM_NCCREATE: {

				std::cout << "Create Window" << std::endl;

				break;
			}

			case WM_DESTROY: {
				PostQuitMessage(0);
				return 0;
			}
				


		}

		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
	
	//Creates the Application
	bool Application::Initialize()
	{
		WNDCLASS wndClass = {};

		//Set defaults for window struct
		wndClass.lpszClassName = L"BaseWindowClass";
		wndClass.style = 0;
		wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wndClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wndClass.lpszMenuName = 0;
		wndClass.hInstance = 0;
		
		//Callback function to function that handles different OS messages
		wndClass.lpfnWndProc = WindProc; //long ptr to function of window procedure
		
		//Make sure application has different bytes available that can always be accessed from OS/Message system
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;

		//Tell windows that this class is available
		RegisterClass(&wndClass);

		//Cannot expect to use the handle properly, as soon as the function returns
		//It will return a ptr but not a proper handle
		m_WindowHandle = CreateWindow(L"BaseWindowClass", L"KT ENGINE WINDOW", WS_OVERLAPPEDWINDOW, 200, 200, 1200, 720, 0, 0, 0, 0); //refer back to L Param stuff later

		//See if pointer is valid
		if (!m_WindowHandle) {
			return false;
		}

		ShowWindow(m_WindowHandle, SW_SHOW);
		UpdateWindow(m_WindowHandle); //Repaint window

		m_isRunning = true;

		return m_isRunning;
	}
	void Application::Update()
	{
	}
}