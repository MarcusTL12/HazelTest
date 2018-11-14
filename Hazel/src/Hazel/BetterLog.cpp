#include "BetterLog.h"

#include <memory>
#include "spdlog/spdlog.h"

#include "spdlog/sinks/stdout_color_sinks.h"


namespace Hazel {

	std::shared_ptr<spdlog::logger> s_CoreLogger;
	std::shared_ptr<spdlog::logger>	s_ClientLogger;

	template<typename... Args>
	void trace(const char* msg, const Args &... args)
	{
		s_CoreLogger->log(spdlog::level::err, msg, args);
	}


	void InitLog()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("HAZEL");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
		// int a = 7;
		// trace("Test, {0}", a);
	}

	void randomfunc(const char* msg)
	{
		printf(msg);
	}

}

