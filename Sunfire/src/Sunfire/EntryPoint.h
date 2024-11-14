#pragma once

#if defined(SUNFIRE_PLATFORM_WINDOWS) || defined(SUNFIRE_PLATFORM_MACOS)

extern Sunfire::Application* Sunfire::CreateApplication();

int main(int argc, char** argv) 
{
	Sunfire::Log::Init();
	SUNFIRE_CORE_WARN("Initialized Log!");
	int a = 5;
	SUNFIRE_INFO("Hello! Var={0}", a);

	auto app = Sunfire::CreateApplication();
	app->Run();
	delete app;
}

#endif