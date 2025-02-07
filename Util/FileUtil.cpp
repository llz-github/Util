#include "FileUtil.h"

#include <stdexcept>
#include <direct.h>
#include <io.h>
#include <Windows.h>


void FileUtil::GetFileNames(std::string path, std::vector<std::string>& files)
{
	//文件句柄
	//注意：我发现有些文章代码此处是long类型，实测运行中会报错访问异常
	intptr_t hFile = 0;
	//文件信息
	struct _finddata_t fileinfo;
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,递归查找
			//如果不是,把文件绝对路径存入vector中
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