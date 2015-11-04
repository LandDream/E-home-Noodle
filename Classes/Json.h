#ifndef __JSON__
#define __JSON__

#include <iostream>
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
	char * _str;
public:
	static Json * getInstance();
	void setJson(const char * str);
	const char * getJson();

};

#endif
