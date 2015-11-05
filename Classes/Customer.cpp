#include "Customer.h"

Customer::Customer()
{
	fAllTime = 0.f;
	fWaitTime = 0.f;
	fEatTime = 3.0f;
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

Customer* Customer::createCustomer(Node* customer_node)
{
	Customer* customer = Customer::create();
	customer->setCustomer(customer_node);
	return customer;
}

void Customer::setWaitTime(float fTime)
{
	fAllTime = fTime;
	fWaitTime = fTime;
}

bool Customer::spendWaitTime(float fTime)
{
	fWaitTime -= fTime;

	bool is_end = false;
	int nLevel = patientLevel();
	if (nLevel == -1)
	{
		customer_tip->setVisible(false);
		customer_man->setVisible(false);
		for (int i = 0; i < 5; i++)//ÄÍÐÄÂú
		{
			customer_tip->getChildByTag(i + 1)->getChildByName("heart_red")->setVisible(true);
			customer_tip->getChildByTag(i + 1)->getChildByName("heart_half")->setVisible(false);
		}

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
	return is_end;
}

bool Customer::spendEatTime(float fTime)
{
	fEatTime -= fTime;
	bool is_end = false;
	if (fEatTime<0.f)
	{
		customer_tip->setVisible(false);
		customer_man->setVisible(false);
		for (int i = 0; i < 5; i++)//ÄÍÐÄÂú
		{
			customer_tip->getChildByTag(i + 1)->getChildByName("heart_red")->setVisible(true);
			customer_tip->getChildByTag(i + 1)->getChildByName("heart_half")->setVisible(false);
		}

		is_end = true;
	}
	return is_end;
}

void Customer::setCustomer(Node* customer_node)
{
	self_customer = customer_node;
	self_customer->retain();

	customer_man = dynamic_cast<Sprite*>(self_customer->getChildByName("man"));
	customer_man->retain();
	SpriteFrame* frame_eat = SpriteFrameCache::getInstance()->getSpriteFrameByName("white_eat_food1.png");
	customer_man->setDisplayFrame(frame_eat);
	customer_man->setVisible(true);

	customer_tip = self_customer->getChildByName("tip");
	customer_tip->retain();
	customer_tip->setVisible(true);
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

void Customer::setStateEating()
{
	setCustomerState(e_Customer_State_Eating);
	SpriteFrame* frame_eat = SpriteFrameCache::getInstance()->getSpriteFrameByName("white_eat_food2.png");
	customer_man->setDisplayFrame(frame_eat);
}

bool Customer::init()
{
    if ( !Node::init() )
    {
        return false;
    }
	setCustomerState(e_Customer_State_Wait);

    return true;
}
