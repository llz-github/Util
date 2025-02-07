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
	/// <summary>	遍历此目录下所有文件名称</summary>
	///
	/// <remarks>	llz, 2022/3/24. </remarks>
	///
	/// <param name="path">	文件夹路径. </param>
	/// <param name="files">	文件名称列表. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void GetFileNames(std::string path, std::vector<std::string>& files);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	创建文件，文件夹不存在则依次创建 </summary>
	///
	/// <remarks>	llz, 2022/3/24. </remarks>
	///
	/// <param name="FileName">	文件名称（可以带路径）. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool CreateMultipleDirectory(std::string FileName);
};

#endif // FileUtil_H