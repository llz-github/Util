#include "LogUtil.h"

#include <Windows.h>

static struct TimeUtilPrivate
{
	TimeUtilPrivate()
	{

	};
	LARGE_INTEGER startCount;
	LARGE_INTEGER endCount;
	LARGE_INTEGER freq;
};



TimeUtil *TimeUtil::m_instance = NULL;
TimeUtilPrivate *TimeUtil::_p = new TimeUtilPrivate();

TimeUtil* TimeUtil::instance()
{
	if (m_instance == NULL)
	{
		QueryPerformanceFrequency(&_p->freq);
		m_instance = new TimeUtil();
	}
	return m_instance;
}

std::string TimeUtil::GetCurrentTimeString()
{
	SYSTEMTIME stLocal;
	GetLocalTime(&stLocal);
	char _timestamp[32];
	memset(_timestamp, 0, sizeof(_timestamp));
	sprintf_s(_timestamp, "%d-%d-%d %d-%d-%d.%d", stLocal.wYear, stLocal.wMonth, stLocal.wDay, stLocal.wHour, stLocal.wMinute, stLocal.wSecond, stLocal.wMilliseconds);
	return _timestamp;
}

void TimeUtil::TimingStarts()
{
	QueryPerformanceCounter(&_p->startCount);    //开始计时
	UTIL_INSTANCE_LogDebug("开始计时");
}

double TimeUtil::TimingEnds()
{
	QueryPerformanceCounter(&_p->endCount);     //结束计时
	double dbTime = ((double)_p->endCount.QuadPart - (double)_p->startCount.QuadPart) / (double)_p->freq.QuadPart;    //获取时间差
	//std::cout << dbTime * 1000 << "ms" << std::endl;
	UTIL_INSTANCE_LogDebug("计时结束时间为 %d ms" , dbTime * 1000);
	return dbTime * 1000;
}