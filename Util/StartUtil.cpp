#include"StartUtil.h"
#include <Windows.h>

struct StartUtilPrivate
{
	StartUtilPrivate()
	{

	};

};

//互斥量判断程序是否重复启动
bool StartUtil::IsFirstStart(std::string Name)
{
	std::string mutexName = "ZLTools_Mutex_";
	
	UTIL_INSTANCE_GetUtilCongfig("StartUtil.PreMutexName", mutexName);
	mutexName += Name;
	HANDLE hMutex = CreateMutex(NULL, FALSE, mutexName.c_str());

	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		UTIL_INSTANCE_LogError("Another instance is already running.\n");
		HWND handle = FindWindow(nullptr, Name.c_str());
		if (handle != nullptr)
		{
			std::string Message = Name + "软件已启动，请勿重复启动:" ;
			MessageBox(NULL, Message.c_str(), ("提示"), MB_OK);
			UTIL_INSTANCE_LogDebug("已将程序置于界面最前端\n");
			ShowWindow(handle, SW_RESTORE);
			SetForegroundWindow(handle);
		}
	
		return false;
	}
	return true;
}
