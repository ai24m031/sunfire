#include "Application.h"

#include "Sunfire/Events/ApplicationEvent.h"
#include "Sunfire/Log.h"

namespace Sunfire {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SUNFIRE_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SUNFIRE_TRACE(e.ToString());
		}

		while (true);
	}

}