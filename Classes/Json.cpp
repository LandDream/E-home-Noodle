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

const char * Json::getJson(const char * name, int num, const char * str)
{
	string JsonName = String::createWithFormat("res/%s.json", name)->getCString();
	//string JsonName = "res/CUSTOMER.json";
	//JsonName.replace(JsonName.find("CUSTOMER"), sizeof("CUSTOMER") - 1, name);

	string path = CCFileUtils::sharedFileUtils()->fullPathForFilename(JsonName);
	string data = FileUtils::getInstance()->getStringFromFile(path);
	Document doc;

	if (doc.Parse<0>(data.c_str()).HasParseError())
	{
		cout << "error" << endl;
		return NULL;
	}

	if (doc[num].IsObject())
	{
		if (doc[num][str].IsObject())
		{
			log("%s", doc[num][str].GetString());
			_str = doc[num][str].GetString();
		}
		if (doc[num][str].IsNumber())
		{
			log("%d", doc[num][str].GetInt());
			_str = String::createWithFormat("%d", doc[num][str].GetInt())->getCString();
		}
		if (doc[num][str].IsString())
		{
			log("%s", doc[num][str].GetString());
			_str = doc[num][str].GetString();
		}
	}
	if (_str == NULL)
	{
		CCLOG("Error!");
		return NULL;
	}
	return _str;
}

int Json::StorageStar(int Checkpoint, int StarNum)
{
	Checkpoint--;
	string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("res/STORAGE.json");
	string data = FileUtils::getInstance()->getStringFromFile(path);
	Document doc;
	doc.Parse<rapidjson::kParseDefaultFlags>(data.c_str());
	if (doc.Parse<0>(data.c_str()).HasParseError())
	{
		cout << "error" << endl;
		return NULL;
	}
	if (doc[Checkpoint].IsObject())
	{
		if (doc[Checkpoint]["StarNum"].IsNumber())
		{
			doc[Checkpoint]["StarNum"].SetInt(StarNum);
		}
	}
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	doc.Accept(writer);
	FILE * file = fopen(path.c_str(), "w");
	if (file) {
		fputs(buffer.GetString(), file);
		fclose(file);
	}
	return 0;
}
