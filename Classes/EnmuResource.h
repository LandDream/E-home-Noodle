#pragma once

enum e_Food_Basket
{
	e_food_noodle,
	e_food_shallot,
	e_food_dumplings,
	e_food_beff,
	e_food_shrimp,
	e_food_chil,
	e_food_egg,
	e_food_fish,
	e_food_pork,
	e_food_broccol,
	e_food_chicken,
	e_food_mushrooms,
};

enum e_Customer_State
{
	e_Customer_State_None,
	e_Customer_State_Wait,
	e_Customer_State_Eating,
};

typedef struct struct_CUSTOMER
{
	int CUSTOMER_ID = 0;
	std::string CUSTOMER_NAME = "";
	int WAIT_TIME = 0;
	int HAPPY_BONUS = 0;
	int REFLESH_TIME = 0;
	int PUNISH_TIME = 0;
};

typedef struct struct_FOOD
{
	int FOOD_ID = 0;
	std::string FOOD_NAME = "";
	int PRICE = 0;
	int BUY_TIME = 0;
	int NUM_LIMIT = 0;
	int START_NUM = 0;
	int BUY_NUM = 0;
};

typedef struct struct_ITEM
{
	int ITEM_ID = 0;
	std::string ITEM_NAME = "";
	int ITEM_TYPE = 0;
	int ITEM_SOLD_PRICE = 0;
	int ITEM_LEVEL = 0;
	std::string ITEM_SPECIAL_EFFECT = "";
};

typedef struct struct_NOODLES
{
	int NOODLE_ID = 0;
	const char * NOODLE_NAME = "";
	int FOOD[12] = { 0 };
	const char * WORK_TIME = "";
	const char * SOLD_PRICE = "";
};

typedef struct struct_STAGE
{
	int STAGE_ID = 0;
	int FIRST_NOODLE_ID = 0;

	int STAGE_TIME = 0;
};
