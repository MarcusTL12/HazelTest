
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "../../src/Hazel/SimpLog.h"

namespace Hazel
{
namespace Log
{

std::shared_ptr<spdlog::logger> s_CoreLogger;
std::shared_ptr<spdlog::logger> s_ClientLogger;

void Init()
{
	spdlog::set_pattern("%^[%T] %n: %v%$");

	s_CoreLogger = spdlog::stdout_color_mt("HAZEL");
	s_CoreLogger->set_level(spdlog::level::trace);

	s_ClientLogger = spdlog::stdout_color_mt("APP");
	s_ClientLogger->set_level(spdlog::level::trace);
}

void Log(bool core, int level, const char* msg, formType* args, int numArgs)
{
	if (numArgs == 0)
	{
		(core ? s_CoreLogger : s_ClientLogger)->log((spdlog::level::level_enum) level, msg);
		return;
	}

	fmt::basic_format_arg<fmt::format_context> test[numArgs];

	for (int i = 0; i < numArgs; i++)
	{
		switch (args[i].type)
		{
			case formType::INT: test[i] = fmt::internal::make_arg<fmt::format_context>(*((int *) (args[i].value))); break;
			case formType::DOUBLE: test[i] = fmt::internal::make_arg<fmt::format_context>(*((double *) (args[i].value))); break;
			case formType::FLOAT: test[i] = fmt::internal::make_arg<fmt::format_context>(*((float *) (args[i].value))); break;
			case formType::STR: test[i] = fmt::internal::make_arg<fmt::format_context>(((char *) (args[i].value))); break;
			case formType::SHORT: test[i] = fmt::internal::make_arg<fmt::format_context>(*((short *) (args[i].value))); break;
			case formType::CHAR: test[i] = fmt::internal::make_arg<fmt::format_context>(*((char *) (args[i].value))); break;
			case formType::LONG: test[i] = fmt::internal::make_arg<fmt::format_context>(*((long long *) (args[i].value))); break;
		}
	}

	(core ? s_CoreLogger : s_ClientLogger)->log((spdlog::level::level_enum) level, fmt::vformat(msg, fmt::basic_format_args<fmt::format_context>(test, numArgs)));
}


} // namespace Log
} // namespace Hazel
