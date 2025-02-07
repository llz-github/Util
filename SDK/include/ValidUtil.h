#ifndef ValidUtil_H
#define ValidUtil_H

#include "Util.h"
#include "Util_global.h"

#define UTIL_IsValidIp(ipaddress)	ValidUtil::IsValidIp(ipaddress)

class UTIL_EXPORT ValidUtil
{
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	���ip�Ƿ�Ϸ�</summary>
	///
	/// <remarks>	llz, 2022/3/24. </remarks>
	///
	/// <param name="ipaddress">	�����ip. </param>
	/// <Result name="int">	0���Ƿ���ַ  1:������ַ 2���鲥��ַ. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static int IsValidIp(const std::string &ipaddress);
};

#endif // LogUtil_H