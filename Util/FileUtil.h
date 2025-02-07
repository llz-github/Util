#ifndef FileUtil_H
#define FileUtil_H

#include "Util.h"
#include "vector"

#define UTIL_CreateMultipleDirectory(FileName)	FileUtil::CreateMultipleDirectory(FileName)
#define UTIL_GetFileNames(path,files)	FileUtil::GetFileNames(path,files)

class UTIL_EXPORT FileUtil
{
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	������Ŀ¼�������ļ�����</summary>
	///
	/// <remarks>	llz, 2022/3/24. </remarks>
	///
	/// <param name="path">	�ļ���·��. </param>
	/// <param name="files">	�ļ������б�. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void GetFileNames(std::string path, std::vector<std::string>& files);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	�����ļ����ļ��в����������δ��� </summary>
	///
	/// <remarks>	llz, 2022/3/24. </remarks>
	///
	/// <param name="FileName">	�ļ����ƣ����Դ�·����. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool CreateMultipleDirectory(std::string FileName);
};

#endif // FileUtil_H