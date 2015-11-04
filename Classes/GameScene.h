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
	void chooseFood(Ref* pSender);
	void chooseCake(Ref* pSender);
	void makeFood(Ref* pSender);
	void ashcanFood(Ref* pSender);
	void clearFood();
	void cookBook(Ref* pSender);
	void PhoneFood(Ref* pSender);
	bool isTureFood(int base_food[12]);
	void comeCustomer();
	std::string getFoodNameByTag(int nTag);
private:
	std::vector<Sprite*> vec_track;
	std::vector<Sprite*> vec_noodle;
	std::map<int,Node*> vec_customer_tip;
	std::map<int, float> vec_customer_time;

	int array_food[12];
	int array_Customer[5];
	int chooose_food_num;
	Node* rootNode;
};

#endif
