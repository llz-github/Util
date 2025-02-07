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
	/// <summary>	单例. </summary>
	///
	/// <remarks>	llz, 2022/3/24. </remarks>
	//
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static Logger* instance();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	日志输出. </summary>
	///
	/// <remarks>	llz, 2022/3/24. </remarks>
	///
	/// <param name="Level">	日志输出等级. </param>
	/// <param name="file">	要输出日志的文件 </param>
	/// <param name="line">	要输出日志行号 </param>
	/// <param name="format">	日志的内容 </param>
	/// <param name="...">	日志其余参数 </param>
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
