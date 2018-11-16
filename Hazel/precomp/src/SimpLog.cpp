
#include <memory>
#include <vector>
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

void CoreTrace(const char *msg) { s_CoreLogger->trace(msg); }
void CoreInfo(const char *msg) { s_CoreLogger->info(msg); }
void CoreWarn(const char *msg) { s_CoreLogger->warn(msg); }
void CoreError(const char *msg) { s_CoreLogger->error(msg); }
void CoreFatal(const char *msg) { s_CoreLogger->critical(msg); }

void CoreTrace(const char *msg, int &p1) { s_CoreLogger->trace(msg, p1); }
void CoreInfo(const char *msg, int &p1) { s_CoreLogger->info(msg, p1); }
void CoreWarn(const char *msg, int &p1) { s_CoreLogger->warn(msg, p1); }
void CoreError(const char *msg, int &p1) { s_CoreLogger->error(msg, p1); }
void CoreFatal(const char *msg, int &p1) { s_CoreLogger->critical(msg, p1); }

void ClientTrace(const char *msg) { s_ClientLogger->trace(msg); }
void ClientInfo(const char *msg) { s_ClientLogger->info(msg); }
void ClientWarn(const char *msg) { s_ClientLogger->warn(msg); }
void ClientError(const char *msg) { s_ClientLogger->error(msg); }
void ClientFatal(const char *msg) { s_ClientLogger->critical(msg); }

void ClientTrace(const char *msg, int &p1) { s_ClientLogger->trace(msg, p1); }
void ClientInfo(const char *msg, int &p1) { s_ClientLogger->info(msg, p1); }
void ClientWarn(const char *msg, int &p1) { s_ClientLogger->warn(msg, p1); }
void ClientError(const char *msg, int &p1) { s_ClientLogger->error(msg, p1); }
void ClientFatal(const char *msg, int &p1) { s_ClientLogger->critical(msg, p1); }


void TestPrint(const char* msg, std::vector<formType> args)
{
	fmt::basic_format_arg<fmt::format_context> test[args.size()];

	for (int i = 0; i <= args.size(); i++)
	{
		switch (args[i].type)
		{
			case formType::CHAR: test[i] = fmt::internal::make_arg<fmt::format_context>(*((char *) (args[i].value))); break;
			case formType::INT: test[i] = fmt::internal::make_arg<fmt::format_context>(*((int *) (args[i].value))); break;
			case formType::DOUBLE: test[i] = fmt::internal::make_arg<fmt::format_context>(*((double *) (args[i].value))); break;
			case formType::STR: test[i] = fmt::internal::make_arg<fmt::format_context>(((char *) (args[i].value))); break;
		}
	}

	auto a = fmt::basic_format_args<fmt::format_context>(test, args.size());

	auto s = fmt::vformat(msg, a);

	s_CoreLogger->trace(s);
}


} // namespace Log
} // namespace Hazel
