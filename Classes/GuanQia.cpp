#include "GuanQia.h"

GuanQiaLayer::GuanQiaLayer()
{

}

GuanQiaLayer::~GuanQiaLayer()
{

}

bool GuanQiaLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Node * sp = CSLoader::createNode("guanqia.csb");
	addChild(sp);
	ListView * lv = dynamic_cast<ListView*>(sp->getChildByName("LV_rq"));

	for (int i = 1; i <= 10 ; i++)
	{
		Node * wd_up = CSLoader::createNode("guanqia_btn.csb");
		wd_up->setPosition(Vec2(50, -200));
		Button* btn_up = dynamic_cast<Button*>(wd_up->getChildByName("btn_1"));
		btn_up->setSwallowTouches(false);
		Node * wd_down = CSLoader::createNode("guanqia_btn.csb");
		wd_down->setPosition(Vec2(50, -400));
		Button* btn_down = dynamic_cast<Button*>(wd_down->getChildByName("btn_1"));
		btn_down->setSwallowTouches(false);
		Widget* layout = Widget::create();
		layout->addChild(wd_up);
		layout->addChild(wd_down);
		lv->pushBackCustomItem(layout);
	}

	Button* button = dynamic_cast<Button*>(sp->getChildByName("btn_exit"));
	button->addClickEventListener(CC_CALLBACK_1(GuanQiaLayer::exit, this));

	return true;
}

void GuanQiaLayer::exit(Ref * pSender)
{
	this->removeFromParent();
}