#include "UtilDefineBasic.h"
#include "pugixml.hpp"


UtilDefineBasic *UtilDefineBasic::m_instance = NULL;

UtilDefineBasic* UtilDefineBasic::instance()
{
	if (m_instance == NULL)
	{
		m_instance = new UtilDefineBasic();
	}
	return m_instance;
}


bool UtilDefineBasic::GetUtilCongfig(std::string key, int &t)
{
	std::string strXmlFile = SDKPATH + "\\config\\UnitConfig.XUnit";
	//ReadXml(SDKPATH + "\\config\\UnitConfig.XUnit", key);
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(strXmlFile.c_str(), pugi::parse_full, pugi::encoding_auto);
	if (result)
	{
		pugi::xml_node RootNode = doc.select_single_node("Root").node();

		//指定查询
		int num = key.find(".");
		std::string str_UtilNode = key.substr(0, num);
		pugi::xml_node UtilNode = RootNode.select_single_node(str_UtilNode.c_str()).node();

		for (pugi::xml_node node = RootNode.child(str_UtilNode.c_str()).first_child(); node; node = node.next_sibling())
		{
			std::string keyNode = node.attribute("key").value();
			if (keyNode == key)
			{

				t = node.attribute("value").as_int();
				
				return true;
			}
		}
	}
	return false;
}

bool UtilDefineBasic::GetUtilCongfig(std::string key, std::string &t)
{
	std::string strXmlFile = SDKPATH + "\\config\\UnitConfig.XUnit";
	//ReadXml(SDKPATH + "\\config\\UnitConfig.XUnit", key);
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(strXmlFile.c_str(), pugi::parse_full, pugi::encoding_auto);
	if (result)
	{
		pugi::xml_node RootNode = doc.select_single_node("Root").node();

		//指定查询
		int num = key.find(".");
		std::string str_UtilNode = key.substr(0, num);
		pugi::xml_node UtilNode = RootNode.select_single_node(str_UtilNode.c_str()).node();

		for (pugi::xml_node node = RootNode.child(str_UtilNode.c_str()).first_child(); node; node = node.next_sibling())
		{
			std::string keyNode = node.attribute("key").value();
			if (keyNode == key)
			{
				//if (std::is_same<T, int>::value)
				//{
				//	t = node.attribute("type").as_int();
				//}
				//if (std::is_same<T, std::string>::value)
				{
					t = node.attribute("value").value();
				}
				//if (std::is_same<T, bool>::value)
				//	t = node.attribute("type").as_bool();
				//if (std::is_same<T, unsigned int>::value)
				//	t = node.attribute("type").as_uint();
				//if (std::is_same<T, double>::value)
				//	t = node.attribute("type").as_double();
				//if (std::is_same<T, float>::value)
				//	t = node.attribute("type").as_float();
				return true;
			}
		}
	}
	return false;
}

bool UtilDefineBasic::GetUtilCongfig(std::string key, double &t)
{
	std::string strXmlFile = SDKPATH + "\\config\\UnitConfig.XUnit";
	//ReadXml(SDKPATH + "\\config\\UnitConfig.XUnit", key);
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(strXmlFile.c_str(), pugi::parse_full, pugi::encoding_auto);
	if (result)
	{
		pugi::xml_node RootNode = doc.select_single_node("Root").node();

		//指定查询
		int num = key.find(".");
		std::string str_UtilNode = key.substr(0, num);
		pugi::xml_node UtilNode = RootNode.select_single_node(str_UtilNode.c_str()).node();

		for (pugi::xml_node node = RootNode.child(str_UtilNode.c_str()).first_child(); node; node = node.next_sibling())
		{
			std::string keyNode = node.attribute("key").value();
			if (keyNode == key)
			{

				t = node.attribute("value").as_double();
				return true;
			}
		}
	}
	return false;
}