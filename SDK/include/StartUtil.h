#ifndef StartUtil_H
#define StartUtil_H

#include "Util.h"
#include "Util_global.h"

#define UTIL_IsFirstStart(Name) StartUtil::IsFirstStart(Name)

struct StartUtilPrivate;

class UTIL_EXPORT StartUtil
{
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	�жϻ�����Ϊ${NAME}�ĳ����Ƿ��һ������. </summary>
	///
	/// <remarks>	llz, 2022/3/24. </remarks>
	///
	/// <param name="Name">	����������. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool IsFirstStart(std::string Name);

private:
	
	StartUtilPrivate *_p;
};


#endif // StartUtil_H
