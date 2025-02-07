#ifndef LogUtil_H
#define LogUtil_H

#include "Util.h"
#include "Util_global.h"

#define UTIL_INSTANCE_LogDebug(format, ...) \
	Logger::instance()->log(Logger::DEBUG, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define UTIL_INSTANCE_LogInfo(format, ...) \
	Logger::instance()->log(Logger::INFO, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define UTIL_INSTANCE_LogWarn(format, ...) \
	Logger::instance()->log(Logger::WARN, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define UTIL_INSTANCE_LogError(format, ...) \
	Logger::instance()->log(Logger::ERRORS, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define UTIL_INSTANCE_LogFatal(format, ...) \
	Logger::instance()->log(Logger::FATAL, __FILE__, __LINE__, format, ##__VA_ARGS__)

struct LoggerPrivate;

class UTIL_EXPORT Logger
{
public:
	enum Level
	{
		DEBUG = 0,
		INFO,
		WARN,
		ERRORS,
		FATAL,
		LEVEL_COUNT
	};
	
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	����. </summary>
	///
	/// <remarks>	llz, 2022/3/24. </remarks>
	//
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static Logger* instance();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	��־���. </summary>
	///
	/// <remarks>	llz, 2022/3/24. </remarks>
	///
	/// <param name="Level">	��־����ȼ�. </param>
	/// <param name="file">	Ҫ�����־���ļ� </param>
	/// <param name="line">	Ҫ�����־�к� </param>
	/// <param name="format">	��־������ </param>
	/// <param name="...">	��־������� </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void log(Level level, const char* file, int line, const char* format, ...);


private:
	Logger();
	~Logger();
	void rotate();
	void open(const std::string &filename);
	void close();
	void MaxSize(int bytes);
	void level(int level);
private:

	static const char* s_level[LEVEL_COUNT];
	static Logger *m_instance;
	
	LoggerPrivate *_p;
};


#endif // LogUtil_H
