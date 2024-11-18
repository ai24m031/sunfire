#pragma once

#ifdef SUNFIRE_PLATFORM_WINDOWS
	#ifdef SUNFIRE_BUILD_DLL
		#define SUNFIRE_API __declspec(dllexport)
	#else
		#define SUNFIRE_API __declspec(dllimport)
	#endif
#elif SUNFIRE_PLATFORM_MACOS
	#ifdef SUNFIRE_BUILD_DLL
		#define SUNFIRE_API __attribute__((visibility("default")))
	#else
		#define SUNFIRE_API __attribute__((visibility("default")))
	#endif
#else
	#error Sunfire only supports Windows!
#endif

#define BIT(x) (1 << x)