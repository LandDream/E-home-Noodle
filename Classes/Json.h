#ifndef __JSON__
#define __JSON__

#include <iostream>
using namespace std;
#include "cocos2d.h"
using namespace cocos2d;

#include "json/document.h"
#include "json/rapidjson.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
using namespace rapidjson;
struct struct_NOODLES
{
	int NOODLE_ID = 0;
	std::string NOODLE_NAME = "";
	int FOOD_ID_1 = 0;
	int FOOD_ID_2 = 0;
	int FOOD_ID_3 = 0;
	int FOOD_ID_4 = 0;
	int FOOD_ID_5 = 0;
	int FOOD_ID_6 = 0;
	int FOOD_ID_7 = 0;
	int FOOD_ID_8 = 0;
	int FOOD_ID_9 = 0;
	int FOOD_ID_10 = 0;
	int FOOD_ID_11 = 0;
	int FOOD_ID_12 = 0;
	std::string WORK_TIME = "";
	std::string SOLD_PRICE = "";
};

class Json
{
private:
	Json();
	const char * _str;
public:
	static Json * getInstance();
	const char * getJson(const char * name,int num, const char * str);
};

#endif
