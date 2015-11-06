#include "Customer.h"
#include "Json.h"

Customer::Customer()
{
	customer_id = 0;
	noodle_id = 0;
	patient_level = 0;
	fAllTime = 0.f;
	fWaitTime = 0.f;
	fEatTime = 3.0f;
	fReflesh_time = 0.f;
	fPunish_time = 0.f;
	fDelayTime = 0.f;
	str_name = "";
	customer_man = nullptr;
	customer_tip = nullptr;
	self_customer = nullptr;
	e_customer_state = e_Customer_State_None;
}

Customer::~Customer()
{
	customer_man->release();
	customer_tip->release();
	self_customer->release();
}

Customer* Customer::createCustomer(Node* customer_node, struct_MAN* struct_man)
{
	Customer* customer = Customer::create();
	customer->setCustomer(customer_node, struct_man);
	return customer;
}

void Customer::setWaitTime(float fTime)
{
	fAllTime = fTime;
	fWaitTime = fTime;
}

bool Customer::spendTime(float fTime)
{
	bool is_end = false;
	if (fDelayTime > 0.f)
	{
		fDelayTime -= fTime;
	}
	else
	{
		if (e_customer_state == e_Customer_State_Eat)
		{
			is_end = spendEatTime(fTime);
		}
		else
		{
			is_end = spendWaitTime(fTime);
		}
	}
	return is_end;
}

bool Customer::spendWaitTime(float fTime)
{
	fWaitTime -= fTime;

	bool is_end = false;
	int nLevel = patientLevel();
	if (nLevel == -1)
	{
		reductionAll();

		is_end = true;
	}
	else if (nLevel % 2 == 1)
	{
		customer_tip->getChildByTag((nLevel + 1) / 2)->getChildByName("heart_half")->setVisible(true);
		customer_tip->getChildByTag((nLevel + 1) / 2)->getChildByName("heart_red")->setVisible(false);
	}
	else if (nLevel < 9)
	{
		customer_tip->getChildByTag(nLevel / 2 + 1)->getChildByName("heart_half")->setVisible(false);
	}

	if (patient_level != nLevel)
	{
		patient_level = nLevel;
		if (patient_level == 7)
		{
			setState(e_Customer_State_Worry);
		}
		else if (patient_level == 3)
		{
			setState(e_Customer_State_Angry);
		}
	}

	return is_end;
}

bool Customer::spendEatTime(float fTime)
{
	fEatTime -= fTime;

	bool is_end = false;
	if (fEatTime < 0.f)
	{
		reductionAll();

		is_end = true;
	}
	return is_end;
}

void Customer::setCustomer(Node* customer_node, struct_MAN* struct_man)
{
	self_customer = customer_node;
	self_customer->retain();

	customer_man = dynamic_cast<Sprite*>(self_customer->getChildByName("man"));
	customer_man->retain();
	customer_man->setVisible(true);

	customer_tip = self_customer->getChildByName("tip");
	customer_tip->retain();
	customer_tip->setVisible(true);

	setState(e_Customer_State_Wait);

	//设置顾客基本信息
	SpriteFrame* frame_eat = SpriteFrameCache::getInstance()->getSpriteFrameByName("game_lady_wait_1.png");
	customer_man->setDisplayFrame(frame_eat);

	customer_id = struct_man->MAN_ID;
	noodle_id = struct_man->NOODLE_ID;

	struct_CUSTOMER* struct_customer = Json::getInstance()->getCustomerByID(customer_id);
	str_name = struct_customer->CUSTOMER_NAME;
	setWaitTime(struct_customer->WAIT_TIME);
	nHappy_bonus = struct_customer->HAPPY_BONUS;
	fReflesh_time = struct_customer->REFLESH_TIME;
	fPunish_time = struct_customer->PUNISH_TIME;

	String* str_noodle = String::createWithFormat("game1_icon_noodles_%d.png", noodle_id);
	SpriteFrame* frame_noodle = SpriteFrameCache::getInstance()->getSpriteFrameByName(str_noodle->getCString());
	Sprite* sprite_noodle = dynamic_cast<Sprite*>(customer_tip->getChildByName("noodle"));
	sprite_noodle->setDisplayFrame(frame_noodle);
}

int Customer::patientLevel()
{
	int nLevel = -1;
	for (int i = 0; i <11; i++)
	{
		if (fWaitTime > fAllTime * MAX((9.5f - i), 0.f) * 0.1)
		{
			nLevel = 10 - i;
			break;
		}
	}
	return nLevel;
}

void Customer::reductionAll()//一切还�?
{
	customer_tip->setVisible(false);
	customer_man->setVisible(false);
	for (int i = 0; i < MAX_CUSTOMER; i++)//耐心�?
	{
		customer_tip->getChildByTag(i + 1)->getChildByName("heart_red")->setVisible(true);
		customer_tip->getChildByTag(i + 1)->getChildByName("heart_half")->setVisible(false);
	}
}

void Customer::addDelayTime()
{
	fDelayTime = 3.0f;
}

bool Customer::eatNoodle(int noodleID)
{
	bool is_eat = e_customer_state > e_Customer_State_Eat && noodleID == noodle_id;
	if (is_eat)
	{
		setState(e_Customer_State_Eat);
	}

	return is_eat;
}

float Customer::getRefleshTime()
{
	return fReflesh_time;
}

void Customer::setState(e_Customer_State eState)
{	
	SpriteFrame* frame_eat = nullptr;
	switch (eState)
	{
		case e_Customer_State_Eat:
			frame_eat = SpriteFrameCache::getInstance()->getSpriteFrameByName("game_lady_eat_2.png");
			break;
		case e_Customer_State_Wait:
			frame_eat = SpriteFrameCache::getInstance()->getSpriteFrameByName("game_lady_wait_2.png");
			break;
		case e_Customer_State_Worry:
			frame_eat = SpriteFrameCache::getInstance()->getSpriteFrameByName("game_lady_worry_2.png");
			break;
		case e_Customer_State_Angry:
			frame_eat = SpriteFrameCache::getInstance()->getSpriteFrameByName("game_lady_angry_2.png");
			break;
		default:
			break;
	}
	customer_man->setDisplayFrame(frame_eat);
	setCustomerState(eState);
}

bool Customer::init()
{
    if ( !Node::init() )
    {
        return false;
    }

    return true;
}
