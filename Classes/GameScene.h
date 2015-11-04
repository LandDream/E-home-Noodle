#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "EnmuResource.h"
#include "Json.h"
USING_NS_CC;
using namespace cocostudio::timeline;
using namespace ui;
class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameScene);
	GameScene();
	~GameScene();

	void update(float delta);
	void chooseFood(Ref* pSender, Widget::TouchEventType type);
	std::string getFoodNameByTag(int nTag);
private:
	std::vector<Sprite*> vec_track;
	int chooose_food_id;
	Node* rootNode;
};

#endif
