#include"StartUtil.h"
#include <Windows.h>

struct StartUtilPrivate
{
	StartUtilPrivate()
	{

	};

};

//�������жϳ����Ƿ��ظ�����
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
			std::string Message = Name + "����������������ظ�����:" ;
			MessageBox(NULL, Message.c_str(), ("��ʾ"), MB_OK);
			UTIL_INSTANCE_LogDebug("�ѽ��������ڽ�����ǰ��\n");
			ShowWindow(handle, SW_RESTORE);
			SetForegroundWindow(handle);
		}
	
		return false;
	}
	return true;
}
