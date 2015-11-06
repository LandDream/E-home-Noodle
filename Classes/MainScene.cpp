#include "MainScene.h"
#include "GameScene.h"


MainScene::MainScene()
{
	rootNode = nullptr;
}

MainScene::~MainScene()
{
	rootNode = nullptr;
}

Scene * MainScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainScene::create();
	scene->addChild(layer);
	return scene;
}

bool MainScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	rootNode = CSLoader::createNode("mainScence.csb");
	this->addChild(rootNode);

	auto start_btn = dynamic_cast<Button*>(rootNode->getChildByTag(200));
	start_btn->addClickEventListener(CC_CALLBACK_1(MainScene::StartGameScene,this));

	auto chooselev_btn = dynamic_cast<Button*>(rootNode->getChildByTag(201));
	chooselev_btn->addClickEventListener(CC_CALLBACK_1(MainScene::OpenChooseLayer, this));

	auto help_btn = dynamic_cast<Button*>(rootNode->getChildByTag(202));
	help_btn->addClickEventListener(CC_CALLBACK_1(MainScene::OpenHelpLayer, this));

	auto seting_btn = dynamic_cast<Button*>(rootNode->getChildByTag(203));
	seting_btn->addClickEventListener(CC_CALLBACK_1(MainScene::OpenSetingLayer, this));

	auto share_btn = dynamic_cast<Button*>(rootNode->getChildByTag(204));
	share_btn->addClickEventListener(CC_CALLBACK_1(MainScene::OpenShareLayer, this));

	auto about_btn = dynamic_cast<Button*>(rootNode->getChildByTag(205));
	about_btn->addClickEventListener(CC_CALLBACK_1(MainScene::OpenAboutLayer, this));

	auto shop_btn = dynamic_cast<Button*>(rootNode->getChildByTag(206));
	shop_btn->addClickEventListener(CC_CALLBACK_1(MainScene::OpenShopLayer, this));

	auto challenge_btn = dynamic_cast<Button*>(rootNode->getChildByTag(207));
	challenge_btn->addClickEventListener(CC_CALLBACK_1(MainScene::OpenchallengeSceneLayer, this));

	auto sp_action = dynamic_cast<Sprite*>(rootNode->getChildByTag(208));
	sp_action->setScale(0.6f);
	ActionInterval * act1 = ScaleBy::create(.8f, 0.7f);
	sp_action->runAction(RepeatForever::create(Sequence::create(act1, act1->reverse(), nullptr)));
	return true;
}

void MainScene::StartGameScene(Ref * pSender)
{
	Json::getInstance()->setCurStage(2);
	Director::getInstance()->replaceScene(GameScene::createScene());
}

void MainScene::OpenChooseLayer(Ref * pSender)
{

}

void MainScene::OpenHelpLayer(Ref * pSender)
{

}

void MainScene::OpenSetingLayer(Ref * pSender)
{

}

void MainScene::OpenShareLayer(Ref * pSender)
{

}

void MainScene::OpenAboutLayer(Ref * pSender)
{
}

void MainScene::OpenShopLayer(Ref * pSender)
{
}

void MainScene::OpenchallengeSceneLayer(Ref * pSender)
{

}
