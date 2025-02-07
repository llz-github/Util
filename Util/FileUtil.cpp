#include "FileUtil.h"

#include <stdexcept>
#include <direct.h>
#include <io.h>
#include <Windows.h>


void FileUtil::GetFileNames(std::string path, std::vector<std::string>& files)
{
	//�ļ����
	//ע�⣺�ҷ�����Щ���´���˴���long���ͣ�ʵ�������лᱨ������쳣
	intptr_t hFile = 0;
	//�ļ���Ϣ
	struct _finddata_t fileinfo;
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//�����Ŀ¼,�ݹ����
			//�������,���ļ�����·������vector��
			if ((fileinfo.attrib & _A_ARCH))
			{
				files.push_back(fileinfo.name);
			}

		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

bool FileUtil::CreateMultipleDirectory(std::string FileName)
{
	if (_access(FileName.c_str(), 0) == 0)
	{
		return true;
	}

	std::string sub;
	for (int i = 0; i < FileName.size(); i++)
	{
		sub.push_back(FileName[i]);
		if (FileName[i] == '\\' || FileName[i] == '/')
		{
			if (_access(sub.c_str(), 0) == -1)
			{
				if (-1 == _mkdir(sub.c_str()))
				{
					return false;
				}
			}
		}
	}
	return true;
}