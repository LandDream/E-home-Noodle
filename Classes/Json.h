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
	struct_CUSTOMER* struct_customer;
	struct_FOOD* struct_food;
	struct_ITEM* struct_item;
	struct_NOODLES* struct_noodles;
	struct_STAGE* struct_stage;
	struct_NOODLE_RATE* struct_noodle_rate;
	struct_MAN* struct_man;
	std::vector<struct_CUSTOMER*> vec_struct_customer;
	std::vector<struct_FOOD*> vec_struct_food;
	std::vector<struct_ITEM*> vec_struct_item;
	std::vector<struct_NOODLES*> vec_struct_noodles;
	std::vector<struct_STAGE*> vec_struct_stage;
	
public:
	static Json * getInstance();
	const char * getJson(const char * name,int num, const char * str);
	void readJson();
	void readCustomerJson();
	void readFoodJson();
	void readItemJson();
	void readNoodlesJson();
	void readStageJson();
	struct_MAN* getNewCustomer();
	int StorageStar(int Checkpoint, int StarNum);
	int getNoodlesID(int (&array_food)[12]);
	CC_SYNTHESIZE(int, nCurStage, CurStage);
	struct_CUSTOMER* getCustomerByID(int nID);
};

#endif
