
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "SimpLog.h"

namespace Hazel {
	namespace Log {

		std::shared_ptr<spdlog::logger> s_CoreLogger;
		std::shared_ptr<spdlog::logger>	s_ClientLogger;

		void Init()
		{
			spdlog::set_pattern("%^[%T] %n: %v%$");

			s_CoreLogger = spdlog::stdout_color_mt("HAZEL");
			s_CoreLogger->set_level(spdlog::level::trace);

			s_ClientLogger = spdlog::stdout_color_mt("APP");
			s_ClientLogger->set_level(spdlog::level::trace);
		}

		void CoreTrace(const char* msg)
		{
			s_CoreLogger->trace(msg);
		}

		void CoreInfo(const char* msg)
		{
			s_CoreLogger->info(msg);
		}

		void CoreWarn(const char* msg)
		{
			s_CoreLogger->warn(msg);
		}

		void CoreError(const char* msg)
		{
			s_CoreLogger->error(msg);
		}

		void CoreFatal(const char* msg)
		{
			s_CoreLogger->critical(msg);
		}

	}
}

