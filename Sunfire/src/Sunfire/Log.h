#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Sunfire {

	class SUNFIRE_API Log 
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define SUNFIRE_CORE_TRACE(...)			::Sunfire::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SUNFIRE_CORE_INFO(...)			::Sunfire::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SUNFIRE_CORE_WARN(...)			::Sunfire::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SUNFIRE_CORE_ERROR(...)			::Sunfire::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SUNFIRE_CORE_CRITICAL(...)		::Sunfire::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define SUNFIRE_TRACE(...)				::Sunfire::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SUNFIRE_INFO(...)				::Sunfire::Log::GetClientLogger()->info(__VA_ARGS__)
#define SUNFIRE_WARN(...)				::Sunfire::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SUNFIRE_ERROR(...)				::Sunfire::Log::GetClientLogger()->error(__VA_ARGS__)
#define SUNFIRE_CRITICAL(...)			::Sunfire::Log::GetClientLogger()->critical(__VA_ARGS__)