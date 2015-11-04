#include "GameScene.h"
#define TRACK_LONG 23
#define CHOOSE_FOOD_NUM 3
Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);

    return scene;
}

GameScene::GameScene()
{
	chooose_food_id = 0;
	vec_track.clear();
	rootNode = nullptr;
}

GameScene::~GameScene()
{

}

bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    rootNode = CSLoader::createNode("GameScene.csb");
    addChild(rootNode);

	//食材盒选菜
	for (size_t i = 0; i < 12; i++)
	{
		Button* button = dynamic_cast<Button*>(rootNode->getChildByName("FoodBasket")->getChildByTag(i));
		button->setTag(i);
		button->addTouchEventListener(CC_CALLBACK_2(GameScene::chooseFood, this));
	}
	//传送带
	for (int i = 0; i < TRACK_LONG; i++)
	{
		Sprite* spr_track = Sprite::createWithSpriteFrameName("game1_icon_track.png");
		spr_track->setPosition(Vec2(i * 62, 328));
		spr_track->setZOrder(TRACK_LONG - i);
		this->addChild(spr_track);
		vec_track.push_back(spr_track);
	}
	this->scheduleUpdate();
    return true;
}

void GameScene::chooseFood(Ref* pSender, Widget::TouchEventType type)
{
	chooose_food_id++;
	if (chooose_food_id > CHOOSE_FOOD_NUM)
	{
		return;
	}
	Button* button = dynamic_cast<Button*>(pSender);
	int foodTag = button->getTag();
	
	SpriteFrame* food_frame =  SpriteFrameCache::getInstance()->getSpriteFrameByName(getFoodNameByTag(foodTag));
	Sprite* spr_food = dynamic_cast<Sprite*>(rootNode->getChildByName("Board")->getChildByTag(chooose_food_id));
	spr_food->setDisplayFrame(food_frame);
	spr_food->setVisible(true);
}

void GameScene::update(float delta)
{
	//传送带
	if (vec_track.size() > 0)
	{
		for (auto it : vec_track)
		{
			if (it->getPositionX() <= -31)
			{
				it->setPositionX(it->getPositionX() + 1427);
			}
			it->setPositionX(it->getPositionX() - 3);
		}
	}
}

std::string GameScene::getFoodNameByTag(int nTag)
{
	return "game1_icon_food_noodles01.png";
}

