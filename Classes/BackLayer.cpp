#pragma once
#include "BackLayer.h"
#include "MainScene.h"

BackLayer::BackLayer()
{

}

BackLayer::~BackLayer()
{

}

bool BackLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Node * rootNode = CSLoader::createNode("BackLayer.csb");
	addChild(rootNode);

	Button* close_btn = dynamic_cast<Button*>(rootNode->getChildByName("close_btn"));
	close_btn->addClickEventListener(CC_CALLBACK_1(BackLayer::CloseCallBack,this));

	Button* close_btn_ = dynamic_cast<Button*>(rootNode->getChildByName("back_btn"));
	close_btn_->addClickEventListener(CC_CALLBACK_1(BackLayer::BackCallBack, this));
	return true;
}

void BackLayer::CloseCallBack(Ref * pSender)
{
	this->removeFromParentAndCleanup(true);
}

void BackLayer::BackCallBack(Ref * pSender)
{
	Director::getInstance()->replaceScene(MainScene::createScene());
}
