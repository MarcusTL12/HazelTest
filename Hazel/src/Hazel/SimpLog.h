

namespace Hazel {
	namespace Log {

		void Init();
		
		void CoreTrace(const char* msg);
		void CoreInfo(const char* msg);
		void CoreWarn(const char* msg);
		void CoreError(const char* msg);
		void CoreFatal(const char* msg);

	}
}


#define HZ_CORE_TRACE(...) ::Hazel::Log::CoreTrace(__VA_ARGS__)
#define HZ_CORE_INFO(...) ::Hazel::Log::CoreInfo(__VA_ARGS__)
#define HZ_CORE_WARN(...) ::Hazel::Log::CoreWarn(__VA_ARGS__)
#define HZ_CORE_ERROR(...) ::Hazel::Log::CoreError(__VA_ARGS__)
#define HZ_CORE_FATAL(...) ::Hazel::Log::CoreFatal(__VA_ARGS__)


// #define HZ_CORE_TRACE(...) ::Hazel::Log::CoreTrace(__VA_ARGS__)
// #define HZ_CORE_INFO(...) ::Hazel::Log::CoreInfo(__VA_ARGS__)
// #define HZ_CORE_WARN(...) ::Hazel::Log::CoreWarn(__VA_ARGS__)
// #define HZ_CORE_ERROR(...) ::Hazel::Log::CoreError(__VA_ARGS__)
// #define HZ_CORE_FATAL(...) ::Hazel::Log::CoreFatal(__VA_ARGS__)

