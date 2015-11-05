#include "Json.h"

static Json * _intance = nullptr;
Json::Json()
{
	_str = "";
	vec_struct_noodles.clear();
	str_noodles = nullptr;
}
Json::~Json()
{
	delete str_noodles;
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
	string JsonName = String::createWithFormat("data/%s.json", name)->getCString();

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
			CCLOG("%s", doc[num][str].GetString());
			_str = doc[num][str].GetString();
		}
		if (doc[num][str].IsNumber())
		{
			CCLOG("%d", doc[num][str].GetInt());
			_str = String::createWithFormat("%d", doc[num][str].GetInt())->getCString();
		}
		if (doc[num][str].IsString())
		{
			CCLOG("%s", doc[num][str].GetString());
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


void Json::readJson()
{
	makeCookBook();
}

void Json::makeCookBook()
{
	for (int i = 0; i < 30; i++)
	{
		str_noodles = nullptr;
		str_noodles = new struct_NOODLES;

		const char * c_json = getJson("NOODLES", i, "NOODLE_ID");
		str_noodles->NOODLE_ID = std::atoi(c_json);

		str_noodles->NOODLE_NAME = getJson("NOODLES", i, "NOODLE_NAME");

		str_noodles->WORK_TIME = getJson("NOODLES", i, "WORK_TIME");

		str_noodles->SOLD_PRICE = getJson("NOODLES", i, "SOLD_PRICE");

		for (int j = 0; j < 12; j++)
		{
			String* str_food = String::createWithFormat("FOOD_ID_%d", j + 1);
			c_json = getJson("NOODLES", i, str_food->getCString());
			str_noodles->FOOD[j] = std::atoi(c_json);
		}
		
		vec_struct_noodles.push_back(str_noodles);
	}
}

int Json::getNoodlesID(int (&array_food)[12])
{
	assert(vec_struct_noodles.size() >= 0, "NOODLES.json READ FAILED");

	int n_id = 0;
	for (int i = 0; i < vec_struct_noodles.size(); i++)
	{
		bool is_success = true;
		for (int j = 0; j < 12; j++)
		{
			if (array_food[j] != vec_struct_noodles[i]->FOOD[j])
			{
				is_success = false;
				break;;
			}
		}
		if (is_success)
		{
			n_id = i + 1;
			break;
		}
	}
	
	return n_id;
}
