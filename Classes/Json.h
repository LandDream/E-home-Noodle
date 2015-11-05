#ifndef __JSON__
#define __JSON__

#include <iostream>
#include "cocos2d.h"
#include "json/document.h"
#include "json/rapidjson.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
#include "EnmuResource.h"

using namespace cocos2d;
using namespace std;
using namespace rapidjson;
class Json
{
private:
	Json();
	~Json();
	const char * _str;
	struct_NOODLES* str_noodles;
	std::vector<struct_NOODLES*> vec_struct_noodles;
public:
	static Json * getInstance();
	const char * getJson(const char * name,int num, const char * str);
	int StorageStar(int Checkpoint, int StarNum);

	std::vector<struct_NOODLES*> getCookBook();
	void makeCookBook();
	int getNoodlesID(int (&array_food)[12]);
	void readJson();
};

#endif
