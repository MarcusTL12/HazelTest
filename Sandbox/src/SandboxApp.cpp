#include "Hazel.h"
#include <vector>

class Sandbox : public Hazel::Application
{
  public:
	Sandbox()
	{
		HZ_CLIENT_INFO("Welcome To The Sandbox App!");
		// int a = 0;
		// HZ_CLIENT_TRACE("Testing with arg a = {0}", a);

		int a = 500;
		double b = 7.3;
		char c = 'd';
		const char *d = "Jallaballa";

		// std::vector<Hazel::Log::formType> lst = {Hazel::Log::formType(b), Hazel::Log::formType(a), Hazel::Log::formType(c), Hazel::Log::formType(d)};
		
		// Hazel::Log::TestPrint("d = {3}, a = {1}, b = {0}, c = {2}", lst);

		Hazel::Log::CallPrint("d = {3}, a = {1}, b = {0}, c = {2}", b, a, c, d);

		HZ_CLIENT_INFO("Setup Succeded!");
	}

	~Sandbox()
	{

	}
};

Hazel::Application *Hazel::CreateApplication()
{
	return new Sandbox();
}
