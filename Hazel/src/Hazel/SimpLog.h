#include <vector>
#include <iostream>

namespace Hazel
{
namespace Log
{

void Init();

void CoreTrace(const char *msg);
void CoreInfo(const char *msg);
void CoreWarn(const char *msg);
void CoreError(const char *msg);
void CoreFatal(const char *msg);

void CoreTrace(const char *msg, int &p1);
void CoreInfo(const char *msg, int &p1);
void CoreWarn(const char *msg, int &p1);
void CoreError(const char *msg, int &p1);
void CoreFatal(const char *msg, int &p1);

void ClientTrace(const char *msg);
void ClientInfo(const char *msg);
void ClientWarn(const char *msg);
void ClientError(const char *msg);
void ClientFatal(const char *msg);

void ClientTrace(const char *msg, int &p1);
void ClientInfo(const char *msg, int &p1);
void ClientWarn(const char *msg, int &p1);
void ClientError(const char *msg, int &p1);
void ClientFatal(const char *msg, int &p1);

struct formType
{
	enum
	{
		CHAR,
		INT,
		DOUBLE,
		STR
	} type;

	void *value;

	formType(const char &val) : type(CHAR), value((void *)(&val)) {}
	formType(const int &val) : type(INT), value((void *)(&val)) {}
	formType(const double &val) : type(DOUBLE), value((void *)(&val)) {}
	formType(const char *val) : type(STR), value((void *)(val)) {}
};

void TestPrint(const char* msg, std::vector<formType> args);


// template <typename T, typename... Ts>
// void MakeArgs(std::vector<formType> &args, T next, Ts&... rest)
// {
// 	std::cout << next << std::endl;
// 	args.push_back(formType(next));
// 	MakeArgs(args, rest...);
// }


struct any {
		enum type {Char, Int, Float, String};
		any(char   e) { m_data.CHAR    = e; m_type = Char;}
		any(int   e) { m_data.INT    = e; m_type = Int;}
		any(float e) { m_data.FLOAT  = e; m_type = Float;}
		any(char* e) { m_data.STRING = e; m_type = String;}
		type get_type() const { return m_type; }
		int get_char() const { return m_data.CHAR; }
		int get_int() const { return m_data.INT; }
		float get_float() const { return m_data.FLOAT; }
		char* get_string() const { return m_data.STRING; }
	private:
		type m_type;
		union {
			char CHAR;
			int   INT;
			double FLOAT;
			char *STRING;
		} m_data;
};



template <typename... Ts>
void CallPrint(const char *msg, Ts&... args)
{
	std::vector<formType> argVec = {};

	std::vector<any> vec = {args...};

	for (int i = 0; i < vec.size(); i++)
	{
		// argVec.push_back(formType(vec[i]));
		std::cout << vec[i].get_type() << std::endl;
	}

	// TestPrint(msg, argVec);
}

} // namespace Log
} // namespace Hazel

#define HZ_CORE_TRACE(...) ::Hazel::Log::CoreTrace(__VA_ARGS__)
#define HZ_CORE_INFO(...) ::Hazel::Log::CoreInfo(__VA_ARGS__)
#define HZ_CORE_WARN(...) ::Hazel::Log::CoreWarn(__VA_ARGS__)
#define HZ_CORE_ERROR(...) ::Hazel::Log::CoreError(__VA_ARGS__)
#define HZ_CORE_FATAL(...) ::Hazel::Log::CoreFatal(__VA_ARGS__)

#define HZ_CLIENT_TRACE(...) ::Hazel::Log::ClientTrace(__VA_ARGS__)
#define HZ_CLIENT_INFO(...) ::Hazel::Log::ClientInfo(__VA_ARGS__)
#define HZ_CLIENT_WARN(...) ::Hazel::Log::ClientWarn(__VA_ARGS__)
#define HZ_CLIENT_ERROR(...) ::Hazel::Log::ClientError(__VA_ARGS__)
#define HZ_CLIENT_FATAL(...) ::Hazel::Log::ClientFatal(__VA_ARGS__)
