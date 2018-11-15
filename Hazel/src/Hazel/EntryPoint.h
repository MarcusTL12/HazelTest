#pragma once

#include "Application.h"

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	// Hazel::Log::Init();
	// HZ_CORE_WARN("Initialized Log!");
	// int a = 3;
	// HZ_INFO("Hello! Var={0}", a);

	Hazel::Log::Init();
	HZ_CORE_WARN("Hallais");

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif
