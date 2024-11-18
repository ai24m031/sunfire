workspace "Sunfire"
	architecture "x64"

	configurations 
	{ 
		 "Debug", 
		 "Release",
		 "Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Sunfire/vendor/GLFW/include"
include "Sunfire/vendor/GLFW"

project "Sunfire"
	location "Sunfire"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sunfirepch.h"
	pchsource "Sunfire/src/sunfirepch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

        links
        {
            "opengl32.lib"
        }

		defines 
		{
			"SUNFIRE_PLATFORM_WINDOWS",
			"SUNFIRE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

        buildoptions "/utf-8"

	filter "system:macosx"
		cppdialect "C++17"
		staticruntime "On"

        links {
            "OpenGL.framework",     -- OpenGL support
            "Cocoa.framework",      -- macOS UI and event handling
            "IOKit.framework",      -- Input/output kit (e.g., joystick support)
            "CoreVideo.framework",  -- Video-related functions
            "CoreFoundation.framework", -- Base macOS functions
        }

		defines
		{
			"SUNFIRE_PLATFORM_MACOS",
			"SUNFIRE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SUNFIRE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SUNFIRE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SUNFIRE_DIST"
		optimize "On"

	filter { "system:windows", "configurations:Release"}
		buildoptions "/MT"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Sunfire/vendor/spdlog/include",
		"Sunfire/src"
	}

	links
	{
		"Sunfire"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"SUNFIRE_PLATFORM_WINDOWS"
		}

        buildoptions "/utf-8"

	filter "system:macosx"
		cppdialect "C++17"
		staticruntime "On"

		defines
		{
			"SUNFIRE_PLATFORM_MACOS"
		}

	filter "configurations:Debug"
		defines "SUNFIRE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SUNFIRE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SUNFIRE_DIST"
		optimize "On"

	filter { "system:windows", "configurations:Release"}
		buildoptions "/MT"