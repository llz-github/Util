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

	//��ȡָ��json�ļ��м�ΪKey��valueֵ
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	��ȡָ��json�ļ��м�ΪKey��valueֵ. </summary>
	///
	/// <remarks>	llz, 2022/3/24. </remarks>
	///
	/// <param name="key">	json��ley����. </param>
	/// <param name="t">	Ҫ���ص�valueֵ. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static bool GetUtilCongfig(std::string key, std::string &t);
	static bool GetUtilCongfig(std::string key, int &t);
	static bool GetUtilCongfig(std::string key, double &t);


private:
	static UtilDefineBasic *m_instance;
};
#endif // UtilDefineBasic_H