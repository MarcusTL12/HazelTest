#include "stdio.h"
#include "Application.h"


namespace Hazel {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		printf("Hallai Hazel!");
		while (true);
	}

}
