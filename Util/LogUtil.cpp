#include "LogUtil.h"

#include <boost/thread/mutex.hpp>
#include <string>
#include <fstream>
#include <Windows.h>

const char* Logger::s_level[LEVEL_COUNT] =
{
	"DEBUG",
	"INFO",
	"WARN",
	"ERRORS",
	"FATAL"
};

struct LoggerPrivate
{
	LoggerPrivate()
	{
		m_max = 52 * 1024;
		m_len = 0;
		m_level = Logger::Level::ERRORS;
		IsFirstMkdir = false;
	};
	std::string m_filename;
	std::ofstream m_fout;
	int m_max;
	int m_len;
	int m_level;
	boost::mutex _mutex;
	bool IsFirstMkdir;
};



Logger *Logger::m_instance = NULL;

Logger::Logger() : _p(new LoggerPrivate())
{
	UtilDefineBasic::GetUtilCongfig("LogUtil.DbgFileMaxValue", _p->m_max);

	UTIL_INSTANCE_GetUtilCongfig("LogUtil.DbgOptValue", _p->m_level);

	open(SDKPATH + "Log\\log.txt");
}

Logger::~Logger()
{
	delete _p;
	close();
}

Logger* Logger::instance()
{
	if (m_instance == NULL)
	{
		m_instance = new Logger();
	}
	return m_instance;
}

void Logger::open(const std::string &filename)
{
	if(!_p->m_fout.fail())
	{
		_p->m_fout.close();
	}

	if (!_p->IsFirstMkdir)
	{
		_p->IsFirstMkdir = true;
		std::string _timestamp = UTIL_INSTANCE_GetCurrentTimeString();

		int n = filename.rfind(".");
		_p->m_filename = filename.substr(0, n) + _timestamp + ".txt";
	}
	
	if(UTIL_CreateMultipleDirectory(_p->m_filename ))
	{
		_p->m_fout.open(_p->m_filename.c_str(), std::ios::app);
		_p->m_fout.seekp(0, std::ios::end);
		_p->m_len = _p->m_fout.tellp();
	}
}

void Logger::close()
{
	_p->m_fout.close();
}

/*0: 黑色 1: 蓝色 2 : 绿色 3 : 红色 4 : 紫色 5 : 黄色 6 : 青色 7 : 白色*/
void SetColor(int fore /*= 7*/, int back = 0 /*= 0*/)
{
	int color = 7;
	switch (fore)
	{
	case 0:
		color = 7;
		break;
	case 1:
		color = 2;
		break;
	case 2:
		color = 5;
		break;
	case 3:
		color = 4;
		break;
	case 4:
		color = 7;
		back = 3;
		break;
	default:
		color = 7;
		back = 0;
		break;
	}
	unsigned char m_color = color;
	m_color += (back << 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_color);
	return;
}

void Logger::log(Level level, const char* file, int line, const char* format, ...)
{
	if (((_p->m_level >> level) & 1) == 0)
	{
		return;
	}

	SetColor(level);

	std::string timestamp = UTIL_INSTANCE_GetCurrentTimeString();
	int len = 0;
	const char * fmt = "%s  %s %s:%d ";
	len = _snprintf(NULL, 0, fmt, timestamp.c_str(), s_level[level], file, line);
	if (len > 0)
	{
		//sprintf_s()
		char * buffer = new char[len + 1];
		_snprintf(buffer, len + 1, fmt, timestamp.c_str(), s_level[level], file, line);
		buffer[len] = 0;
		_p->m_fout << buffer;
		delete buffer;
		_p->m_len += len;
	}

	va_list arg_ptr;
	va_start(arg_ptr, format);
	len = vsnprintf(NULL, 0, format, arg_ptr);
	va_end(arg_ptr);
	if (len > 0)
	{
		char * content = new char[len + 1];
		va_start(arg_ptr, format);
		vsnprintf(content, len + 1, format, arg_ptr);
		va_end(arg_ptr);
		content[len] = 0;
		_p->m_fout << content;
		std::cout << timestamp << " " << s_level[level] << ": " << content << std::endl;
		delete content;
		_p->m_len += len;
	}

	_p->m_fout << "\n";
	_p->m_fout.flush();

	if (_p->m_max > 0 && _p->m_len >= _p->m_max)
	{
		_p->_mutex.lock();
		rotate();
		_p->_mutex.unlock();
	}
	SetColor(7);
}

void Logger::MaxSize(int bytes)
{
	_p->m_max = bytes;
}

void Logger::level(int level)
{
	_p->m_level = level;
}

void Logger::rotate()
{
	close();
	
	std::string timestamp = UTIL_INSTANCE_GetCurrentTimeString();
	timestamp = "_" + timestamp + "back.txt";
	std::string filename = _p->m_filename + timestamp;
	if (rename(_p->m_filename.c_str(), filename.c_str()) != 0)
	{
		std::cout << "ERROR:日志系统崩溃--" << std::string(strerror(errno)) << std::endl;
	}
	open(_p->m_filename);
}