#include "Hazel.h"
#include <vector>

class Sandbox : public Hazel::Application
{
  public:
	Sandbox()
	{
		HZ_INFO("Welcome To The Sandbox App!");

		int a = 500;
		double b = 7.3;
		const char *c = "d";
		const char *d = "Teststring";
		short e = 5;
		char f = 'p';
		long long g = 8589934592;
		float h = 3.14f;

		HZ_WARN("d = {3}, a = {1}, b = {0}, c = {2}, e = {4}, f = {5}, g = {6}, h = {7}", b, a, c, d, e, f, g, h);

		HZ_INFO("Setup Succeded!");
	}

	~Sandbox()
	{

	}
};

Hazel::Application *Hazel::CreateApplication()
{
	return new Sandbox();
}
