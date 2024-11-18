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

#ifdef SUNFIRE_ENABLE_ASSERTS
	#define SUNFIRE_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SUNFIRE_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SUNFIRE_ASSERT(x, ...)
	#define SUNFIRE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)