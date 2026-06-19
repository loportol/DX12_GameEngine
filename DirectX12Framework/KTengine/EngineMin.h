#pragma once

#ifdef KTENGINE_EXPORTS

#define KT_API __declspec(dllexport)

#else

#define KT_API __declspec(dllimport)

#endif 
