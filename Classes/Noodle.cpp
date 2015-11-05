#include "Noodle.h"

Noodle::Noodle()
{
	b_noodle_state = true;
}

Noodle::~Noodle()
{
}

Noodle* Noodle::createNoodle(int nID)
{
	Noodle* customer = Noodle::create();
	customer->setNoodleTpye(nID);
	return customer;
}

void Noodle::setNoodleTpye(int nID)
{
	String* str_noodle;
	if (nID == 0)
	{
		b_noodle_state = false;
		str_noodle = String::createWithFormat("game1_icon_yangchunmian.png");
	}
	else if (nID < 10)
	{
		str_noodle = String::createWithFormat("game1_icon_noodles_100%d.png", nID);
	}
	else
	{
		str_noodle = String::createWithFormat("game1_icon_noodles_10%d.png", nID);
	}
	Sprite* spr_noodle = Sprite::createWithSpriteFrameName(str_noodle->getCString());
	this->addChild(spr_noodle);
}
