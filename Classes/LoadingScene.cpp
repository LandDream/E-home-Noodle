#pragma once

#include "LoadingScene.h"
#include "GameScene.h"
#include "MainScene.h"

LoadingScene::LoadingScene()
{

}

LoadingScene::~LoadingScene()
{

}

Scene * LoadingScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LoadingScene::create();
	scene->addChild(layer);
	return scene;
}

bool LoadingScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Node* rootNode = CSLoader::createNode("res/LogoScene.csb");
	this->addChild(rootNode);
	this->scheduleOnce(schedule_selector(LoadingScene::GoMainScene), 1.0f);
	return true;
}

void LoadingScene::GoMainScene(float d)
{
	Director::getInstance()->replaceScene(MainScene::createScene());
}
