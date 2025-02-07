#ifndef UtilDefineBasic_H
#define UtilDefineBasic_H

#include <iostream>
#define UTIL_INSTANCE_GetUtilCongfig(key, t) UtilDefineBasic::instance()->GetUtilCongfig(key, t)    

static std::string SDKPATH = ".\\";

class UtilDefineBasic
{
	//#define SDKPATH ".\\"
public:
	static UtilDefineBasic* instance();

	//获取指定json文件中键为Key的value值
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	获取指定json文件中键为Key的value值. </summary>
	///
	/// <remarks>	llz, 2022/3/24. </remarks>
	///
	/// <param name="key">	json的ley属性. </param>
	/// <param name="t">	要返回的value值. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static bool GetUtilCongfig(std::string key, std::string &t);
	static bool GetUtilCongfig(std::string key, int &t);
	static bool GetUtilCongfig(std::string key, double &t);


private:
	static UtilDefineBasic *m_instance;
};
#endif // UtilDefineBasic_H