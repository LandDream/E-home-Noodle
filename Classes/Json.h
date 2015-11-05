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
