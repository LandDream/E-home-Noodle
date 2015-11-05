#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "EnmuResource.h"
#include "Customer.h"
#include "Noodle.h"
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
	void comeCustomer(int nID);
	std::string getFoodNameByTag(int nTag);
private:
	Node* rootNode;
	std::vector<Sprite*> vec_track;
	std::vector<Noodle*> vec_noodle;
	std::vector<Node*> vec_customer;
	std::map<int,Customer*> map_customer;
	int array_food[12];
	int chooose_food_num;
	
};
