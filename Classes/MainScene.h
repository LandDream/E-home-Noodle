#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "EnmuResource.h"
#include "Customer.h"
USING_NS_CC;

class MainScene : public Layer
{
public:
	MainScene();
	~MainScene();

	static Scene * createScene();
	virtual bool init();

	CREATE_FUNC(MainScene);
protected:
	Node * rootNode;
public:
	void StartGameScene(Ref * pSender);
	void OpenChooseLayer(Ref * pSender);
	void OpenHelpLayer(Ref * pSender);
	void OpenSetingLayer(Ref * pSender);
	void OpenShareLayer(Ref * pSender);
	void OpenAboutLayer(Ref * pSender);
	void OpenShopLayer(Ref * pSender);
	void OpenchallengeSceneLayer(Ref * pSender);
};
#endif
