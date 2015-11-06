#include "Noodle.h"

Noodle::Noodle()
{
	b_noodle_state = true;
	noodle_id = 0;
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
	noodle_id = nID;
	String* str_noodle;
	if (nID == 0)
	{
		b_noodle_state = false;
		str_noodle = String::createWithFormat("game1_icon_orderbg.png");
	}
	else
	{
		str_noodle = String::createWithFormat("game1_icon_noodles_%d.png", nID);
	}
	Sprite* spr_noodle = Sprite::createWithSpriteFrameName(str_noodle->getCString());
	this->addChild(spr_noodle);
}
