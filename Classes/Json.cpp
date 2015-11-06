#include "Json.h"

static Json * _intance = nullptr;
Json::Json()
{
	_str = "";
	nCurStage = 0;
	struct_customer = nullptr;
	struct_food = nullptr;
	struct_item = nullptr;
	struct_noodles = nullptr;
	struct_stage = nullptr;
	struct_noodle_rate = nullptr;
	struct_man = nullptr;
	vec_struct_customer.clear();
	vec_struct_food.clear();
	vec_struct_item.clear();
	vec_struct_noodles.clear();
	vec_struct_stage.clear();
}
Json::~Json()
{
	delete struct_customer;
	delete struct_food;
	delete struct_item;
	delete struct_noodles;
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
	readCustomerJson();
	readFoodJson();
	readItemJson();
	readNoodlesJson();
	readStageJson();
}

void Json::readCustomerJson()
{
	for (int i = 0; i < 6; i++)
	{
		struct_customer = nullptr;
		struct_customer = new struct_CUSTOMER;

		struct_customer->CUSTOMER_ID = std::atoi(getJson("CUSTOMER", i, "CUSTOMER_ID"));

		struct_customer->CUSTOMER_NAME = getJson("CUSTOMER", i, "CUSTOMER_NAME");

		struct_customer->WAIT_TIME = std::atoi(getJson("CUSTOMER", i, "WAIT_TIME"));

		struct_customer->HAPPY_BONUS = std::atoi(getJson("CUSTOMER", i, "HAPPY_BONUS"));

		struct_customer->REFLESH_TIME = std::atoi(getJson("CUSTOMER", i, "REFLESH_TIME"));

		struct_customer->PUNISH_TIME = std::atoi(getJson("CUSTOMER", i, "PUNISH_TIME"));

		vec_struct_customer.push_back(struct_customer);
	}
}

void Json::readFoodJson()
{
	for (int i = 0; i < 12; i++)
	{
		struct_food = nullptr;
		struct_food = new struct_FOOD;

		struct_food->FOOD_ID = std::atoi(getJson("FOOD", i, "FOOD_ID"));

		struct_food->FOOD_NAME = getJson("FOOD", i, "FOOD_NAME");

		struct_food->PRICE = std::atoi(getJson("FOOD", i, "PRICE"));

		struct_food->BUY_TIME = std::atoi(getJson("FOOD", i, "BUY_TIME"));

		struct_food->NUM_LIMIT = std::atoi(getJson("FOOD", i, "NUM_LIMIT"));

		struct_food->START_NUM = std::atoi(getJson("FOOD", i, "START_NUM"));

		struct_food->BUY_NUM = std::atoi(getJson("FOOD", i, "BUY_NUM"));

		vec_struct_food.push_back(struct_food);
	}
}

void Json::readItemJson()
{
	for (int i = 0; i < 19; i++)
	{
		struct_item = nullptr;
		struct_item = new struct_ITEM;

		struct_item->ITEM_ID = std::atoi(getJson("ITEM", i, "ITEM_ID"));

		struct_item->ITEM_NAME = getJson("ITEM", i, "ITEM_NAME");

		struct_item->ITEM_TYPE = std::atoi(getJson("ITEM", i, "ITEM_TYPE"));

		struct_item->ITEM_SOLD_PRICE = std::atoi(getJson("ITEM", i, "ITEM_SOLD_PRICE"));

		struct_item->ITEM_LEVEL = std::atoi(getJson("ITEM", i, "ITEM_LEVEL"));

		struct_item->ITEM_SPECIAL_EFFECT = getJson("ITEM", i, "ITEM_SPECIAL_EFFECT");

		vec_struct_item.push_back(struct_item);
	}
}

void Json::readNoodlesJson()
{
	for (int i = 0; i < 30; i++)
	{
		struct_noodles = nullptr;
		struct_noodles = new struct_NOODLES;

		struct_noodles->NOODLE_ID = std::atoi(getJson("NOODLES", i, "NOODLE_ID"));

		struct_noodles->NOODLE_NAME = getJson("NOODLES", i, "NOODLE_NAME");

		struct_noodles->WORK_TIME = std::atoi(getJson("NOODLES", i, "WORK_TIME"));

		struct_noodles->SOLD_PRICE = std::atoi(getJson("NOODLES", i, "SOLD_PRICE"));

		for (int j = 0; j < 12; j++)
		{
			String* str_food = String::createWithFormat("FOOD_ID_%d", j + 1);
			struct_noodles->FOOD[j] = std::atoi(getJson("NOODLES", i, str_food->getCString()));
		}

		vec_struct_noodles.push_back(struct_noodles);
	}
}

void Json::readStageJson()
{
	for (int i = 0; i < 12; i++)
	{
		struct_stage = nullptr;
		struct_stage = new struct_STAGE;

		struct_stage->STAGE_ID = std::atoi(getJson("STAGE", i, "STAGE_ID"));

		struct_stage->FIRST_NOODLE_ID = std::atoi(getJson("STAGE", i, "FIRST_NOODLE_ID"));

		for (int j = 0; j < 7; j++)
		{
			String* str_customer_rate = String::createWithFormat("CUSTOMER_%d_RATE", j + 1);
			struct_stage->CUSTOMER_RATE[j] = std::atoi(getJson("STAGE", i, str_customer_rate->getCString()));
		}

		struct_stage->STAGE_TIME = std::atoi(getJson("STAGE", i, "STAGE_TIME"));

		struct_stage->HAPPY_GOLD = std::atoi(getJson("STAGE", i, "HAPPY_GOLD"));

		struct_stage->GOLD_TARGET = std::atoi(getJson("STAGE", i, "GOLD_TARGET"));

		struct_stage->HAPPY_LIMIT_NUM = std::atoi(getJson("STAGE", i, "HAPPY_LIMIT_NUM"));

		struct_stage->ANGRY_LIMIT_NUM = std::atoi(getJson("STAGE", i, "ANGRY_LIMIT_NUM"));

		struct_stage->STAR_GOLD_2 = std::atoi(getJson("STAGE", i, "2STAR_GOLD"));

		struct_stage->STAR_GOLD_3 = std::atoi(getJson("STAGE", i, "3STAR_GOLD"));

		for (int j = 0; j < 10; j++)
		{
			struct_noodle_rate = nullptr;
			struct_noodle_rate = new struct_NOODLE_RATE;

			String* str_noodle_id = String::createWithFormat("NOODLE_%d_ID", j + 1);
			struct_noodle_rate->ID = std::atoi(getJson("STAGE", i, str_noodle_id->getCString()));
			String* str_noodle_rate = String::createWithFormat("NOODLE_%d_RATE", j + 1);
			struct_noodle_rate->RATE = std::atoi(getJson("STAGE", i, str_noodle_rate->getCString()));
			struct_stage->map_NOODLE_RATE[j + 1] = struct_noodle_rate;
		}

		struct_stage->SUM_RATE = std::atoi(getJson("STAGE", i, "SUM_RATE"));

		vec_struct_stage.push_back(struct_stage);
	}
}

struct_MAN* Json::getNewCustomer()
{
	if (nCurStage < 1)
	{
		return nullptr;
	}
	struct_man = nullptr;
	struct_man = new struct_MAN;

	int nRand = rand() % 100;
	int nRate = 0;
	for (int i = 0; i < 7; i++)
	{
		nRate += vec_struct_stage[nCurStage - 1]->CUSTOMER_RATE[i];
		if (nRate > nRand)
		{
			nRate = i;
			break;
		}
	}
	struct_man->MAN_ID = nRate;

	nRand = rand() % 100;
	nRate = 0;
	std::map<int, struct_NOODLE_RATE*> map_NOODLE_RATE = vec_struct_stage[nCurStage - 1]->map_NOODLE_RATE;
	for (int i = 0; i < 10; i++)
	{
		nRate += map_NOODLE_RATE[i + 1]->RATE;
		if (nRate > nRand)
		{
			nRate = map_NOODLE_RATE[i + 1]->ID;
			break;
		}
	}
	struct_man->NOODLE_ID = nRate;
	struct_man->WAIT_TIME = 10.f;
	struct_man->EAT_TIME = 3.f;

	return struct_man;
}

//根据食材得到面条
int Json::getNoodlesID(int(&array_food)[12])
{
	assert(vec_struct_noodles.size() >= 0, "NOODLES.json READ FAILED");

	int noodle_id = 0;//�?�?则制作失�?
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
			noodle_id = vec_struct_noodles[i]->NOODLE_ID;
			break;
		}
	}
	
	return noodle_id;
}
