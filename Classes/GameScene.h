#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "EnmuResource.h"
#include "Customer.h"
#include "Noodle.h"
#include "Json.h"
USING_NS_CC;
using namespace cocostudio::timeline;
using namespace ui;
using namespace std;
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
	void createNewCustomer(int nNum, struct_MAN* struct_man);
	std::string getFoodNameByTag(int nTag);

	CC_SYNTHESIZE(bool, m_recordTime, RecordTime);
	CC_SYNTHESIZE(bool, m_begingame, begingame);

	void OpenBackLayer(Ref * pSender);
	void OpenSetLayer(Ref* pSender);
private:
	Node* rootNode;
	std::vector<Sprite*> vec_track;
	std::vector<Noodle*> vec_noodle;
	std::vector<Node*> vec_customer;
	std::map<int,Customer*> map_customer;
	int array_food[12];
	int chooose_food_num;
private:
	Text * p_level_lab;
	Text * p_time_lab;
	Text * p_Curmoney_lab;
	Text * p_needMoney_lab;
	Text * p_smile_lab;
	Text * p_angry_lab;

	float m_Time;
	float m_base_time;
	LoadingBar * Timer_Bar;
	int curCoin;
public:
	void GetCoin(Ref * pSender);
	void PlayAction(Sprite * sp);
	void SetSmileNum(int count);
	void SetAngryNum(int count);
};
