#include "Help.h"

HelpLayer::HelpLayer()
{

}

HelpLayer::~HelpLayer()
{

}

bool HelpLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Node * sp = CSLoader::createNode("Help.csb");
	addChild(sp);
	
	Button* button = dynamic_cast<Button*>(sp->getChildByName("btn_exit"));
	button->addClickEventListener(CC_CALLBACK_1(HelpLayer::exit, this));

	return true;
}

void HelpLayer::exit(Ref * pSender)
{
	this->removeFromParent();
}