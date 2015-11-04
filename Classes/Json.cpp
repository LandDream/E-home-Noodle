#include "Json.h"

static Json * _intance = nullptr;
Json::Json()
{
	_str = "";
}

Json * Json::getInstance()
{
	if (_intance == nullptr)
	{
		_intance = new Json();
	}
	return _intance;
}

void Json::setJson(const char * str)
{
	std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("res/CUSTOMER.json");
	std::string data = FileUtils::getInstance()->getStringFromFile(path);
	Document doc;

	if (doc.Parse<0>(data.c_str()).HasParseError())
	{
		std::cout << "error" << std::endl;
	}

	CCLOG("12");
	log("%s", doc[0]["ID"].GetString());

	CCLOG("1");





	//std::string path = FileUtils::getInstance()->getWritablePath();
	//path += "Data.json";
	//std::string data = FileUtils::getInstance()->getStringFromFile(path);//获取文件内容

	//Document doc;
	//doc.Parse<rapidjson::kParseDefaultFlags>(data.c_str());//默认的 --json标准格式的 或者说没有损坏的
	//													   //解析
	//													   //log("%s",)
	//if (doc.HasParseError()) {//判断Data.json是否有问题
	//	return;
	//}

	//if (doc.HasMember("username")) {//有没有这个元素
	//	log("%s", doc["username"].GetString());
	//}
	//if (doc["weapon"].IsArray()) {//判断是不是数组
	//	log("%i", doc["weapon"][1].GetInt());
	//}
	//if (doc["weapon"].IsObject()) {//判断是不是字典
	//	log("%s", doc["costume"]["clothing"].GetString());
	//}
	////添加
	//doc.AddMember("name", "name", doc.GetAllocator());//name 分配内存
	//												  //修改
	//doc["costume"]["clothing"].SetString("clothing1");
	////删除
	//doc.RemoveMember("levels");
	////doc还在内存，不是在文件里面
	////doc 键值对 布什一个整体字符串，要变成整个

	//rapidjson::StringBuffer buffer;//初始化缓冲区
	//							   //buffer空的
	//							   //name - value
	//rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	//doc.Accept(writer);//json写入buffer

	//				   //将原来的文件内容覆盖掉
	//FILE * file = fopen(path.c_str(), "w");// w write r read
	//if (file) {
	//	fputs(buffer.GetString(), file);
	//	fclose(file);
	//}

}

const char * Json::getJson()
{
	return 0;
}