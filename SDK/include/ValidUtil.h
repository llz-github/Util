#ifndef ValidUtil_H
#define ValidUtil_H

#include "Util.h"
#include "Util_global.h"

#define UTIL_IsValidIp(ipaddress)	ValidUtil::IsValidIp(ipaddress)

class UTIL_EXPORT ValidUtil
{
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	检查ip是否合法</summary>
	///
	/// <remarks>	llz, 2022/3/24. </remarks>
	///
	/// <param name="ipaddress">	传入的ip. </param>
	/// <Result name="int">	0：非法地址  1:单播地址 2：组播地址. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static int IsValidIp(const std::string &ipaddress);
};

#endif // LogUtil_H