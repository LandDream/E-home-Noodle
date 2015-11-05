#include "Help.h"

Help::Help()
{

}

Help::~Help()
{

}

bool Help::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Node * sp = CSLoader::createNode("Help.csb");
	addChild(sp);
	
	Button* button = dynamic_cast<Button*>(sp->getChildByName("btn_exit"));
	button->addClickEventListener(CC_CALLBACK_1(Help::exit, this));

	return true;
}

void Help::exit(Ref * pSender)
{
	this->removeFromParent();
}