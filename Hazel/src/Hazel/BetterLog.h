#pragma once


namespace Hazel {

	template<typename... Args>
	void trace(const char* msg, const Args &... args);

	void InitLog();

	void randomfunc(const char* msg);

}

