#pragma once

#ifdef SUNFIRE_PLATFORM_WINDOWS

extern Sunfire::Application* Sunfire::CreateApplication();

int main(int argc, char** argv) 
{
	printf("Sunfire Engine\n");
	auto app = Sunfire::CreateApplication();
	app->Run();
	delete app;
}

#endif