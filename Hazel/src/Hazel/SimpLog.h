
namespace Hazel
{
namespace Log
{

void Init();

struct formType
{
	enum
	{
		INT,
		SHORT,
		CHAR,
		LONG,
		DOUBLE,
		FLOAT,
		STR,
		NUL
	} type;

	void *value;

	formType() : type(NUL), value(nullptr) {}
	formType(const int *val) : type(INT), value((void *)(val)) {}
	formType(const short *val) : type(SHORT), value((void *)(val)) {}
	formType(const char *val) : type(CHAR), value((void *)(val)) {}
	formType(const long long *val) : type(LONG), value((void *)(val)) {}
	formType(const double *val) : type(DOUBLE), value((void *)(val)) {}
	formType(const float *val) : type(FLOAT), value((void *)(val)) {}
	formType(const char **val) : type(STR), value((void *)(*val)) {}
};

void Log(bool core, int level, const char* msg, formType* args, int numArgs);

void MakeArgs(formType* args, int &curIndex)
{
}

template <typename T>
void MakeArgs(formType* args, int &curIndex, T next)
{
	args[curIndex++] = formType(next);
}

template <typename T, typename... Ts>
void MakeArgs(formType* args, int &curIndex, T next, Ts... rest)
{
	args[curIndex++] = formType(next);
	MakeArgs(args, curIndex, rest...);
}


template <typename... Ts>
void CallLog(bool core, int level, const char *msg, Ts... args)
{
	int numArgs = sizeof...(args);
	int curIndex = 0;

	formType argVec[numArgs];

	MakeArgs(argVec, curIndex, args...);

	Log(core, level, msg, argVec, numArgs);
}

} // namespace Log
} // namespace Hazel

#define HZ_CORE_TRACE(...) ::Hazel::Log::CallLog(true, 0, __VA_ARGS__)
#define HZ_CORE_INFO(...) ::Hazel::Log::CallLog(true, 2, __VA_ARGS__)
#define HZ_CORE_WARN(...) ::Hazel::Log::CallLog(true, 3, __VA_ARGS__)
#define HZ_CORE_ERROR(...) ::Hazel::Log::CallLog(true, 4, __VA_ARGS__)
#define HZ_CORE_FATAL(...) ::Hazel::Log::CallLog(true, 5, __VA_ARGS__)

#define HZ_CLIENT_TRACE(...) ::Hazel::Log::CallLog(false, 0, __VA_ARGS__)
#define HZ_CLIENT_INFO(...) ::Hazel::Log::CallLog(false, 2, __VA_ARGS__)
#define HZ_CLIENT_WARN(...) ::Hazel::Log::CallLog(false, 3, __VA_ARGS__)
#define HZ_CLIENT_ERROR(...) ::Hazel::Log::CallLog(false, 4, __VA_ARGS__)
#define HZ_CLIENT_FATAL(...) ::Hazel::Log::CallLog(false, 5, __VA_ARGS__)
