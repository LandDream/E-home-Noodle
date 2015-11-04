#include "GameScene.h"
#define TRACK_LONG 23
#define CHOOSE_FOOD_NUM 6
Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);

    return scene;
}

GameScene::GameScene()
{
	chooose_food_num = 0;
	vec_track.clear();
	vec_noodle.clear();
	vec_customer_tip.clear();
	vec_customer_time.clear();
	memset(array_food, 0, sizeof(array_food));
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
	Json::getInstance()->setJson("123");
    rootNode = CSLoader::createNode("GameScene.csb");
    addChild(rootNode);

	//食材盒选菜
	for (int i = 0; i < 12; i++)
	{
		Button* button = dynamic_cast<Button*>(rootNode->getChildByName("FoodBasket")->getChildByTag(i));
		button->setTag(i);
		button->addClickEventListener(CC_CALLBACK_1(GameScene::chooseFood, this));
	}
	//制作食物
	Button* make_btn = dynamic_cast<Button*>(rootNode->getChildByName("make_btn"));
	make_btn->addClickEventListener(CC_CALLBACK_1(GameScene::makeFood, this));
	//扔掉食材
	Button* ashcan_btn = dynamic_cast<Button*>(rootNode->getChildByName("ashcan_btn"));
	ashcan_btn->addClickEventListener(CC_CALLBACK_1(GameScene::ashcanFood, this));
	//拉面秘籍
	Button* cook_btn = dynamic_cast<Button*>(rootNode->getChildByName("cookbook_btn"));
	cook_btn->addClickEventListener(CC_CALLBACK_1(GameScene::cookBook, this));
	//电话
	Button* phone_btn = dynamic_cast<Button*>(rootNode->getChildByName("phone_btn"));
	phone_btn->addClickEventListener(CC_CALLBACK_1(GameScene::PhoneFood, this));
	
	//传送带
	for (int i = 0; i < TRACK_LONG; i++)
	{
		Sprite* spr_track = Sprite::createWithSpriteFrameName("game1_icon_track.png");
		spr_track->setPosition(Vec2(i * 62, 328));
		this->addChild(spr_track);
		vec_track.push_back(spr_track);
	}
	//咖啡---被传送带遮住，未解决
	for (int i = 0; i < 3; i++)
	{
		Button* button = dynamic_cast<Button*>(rootNode->getChildByName("Cake")->getChildByTag(i + 1));
		button->setTag(i);
		button->addClickEventListener(CC_CALLBACK_1(GameScene::chooseCake, this));
	}
	this->scheduleUpdate();
    return true;
}

//食材篮选择食材
void GameScene::chooseFood(Ref* pSender)
{
	Button* button = dynamic_cast<Button*>(pSender);
	int foodTag = button->getTag();
	if (array_food[foodTag] == 1 || chooose_food_num >= CHOOSE_FOOD_NUM)
	{
		return;
	}
	chooose_food_num++;
	array_food[foodTag] = 1;

	SpriteFrame* food_frame =  SpriteFrameCache::getInstance()->getSpriteFrameByName(getFoodNameByTag(foodTag));
	Sprite* spr_food = dynamic_cast<Sprite*>(rootNode->getChildByName("Board")->getChildByTag(chooose_food_num));
	spr_food->setDisplayFrame(food_frame);
	spr_food->setVisible(true);
}

void GameScene::update(float delta)
{
	//传送带
	for (auto itr : vec_track)
	{
		if (itr->getPositionX() <= -31)
		{
			itr->setPositionX(itr->getPositionX() + 1427);
		}
		itr->setPositionX(itr->getPositionX() - 3);
	}
	//面条		
	for (std::vector<Sprite*>::iterator itr = vec_noodle.begin(); itr != vec_noodle.end();)
	{
		if ((*itr)->getPositionX() <= -60)
		{
			itr = vec_noodle.erase(itr);
		}
		else
		{
			(*itr)->setPositionX((*itr)->getPositionX() - 3);
			itr++;
		}
	}
	//顾客
	for (int i = 1; i < 6; i++)
	{
		if (vec_customer_tip[i])
		{
			vec_customer_time[i] -= delta;
			if (vec_customer_time[i] / 10)
			{
			}
		}
	}
}

std::string GameScene::getFoodNameByTag(int nTag)
{
	std::string food_name;
	switch (nTag)
	{
		case e_food_noodle:
			food_name = "game1_icon_food_noodles01.png";
			break;
		case e_food_shallot:
			food_name = "game1_icon_food_shallot01.png";
			break;
		case e_food_dumplings:
			food_name = "game1_icon_food_dumplings01.png";
			break;
		case e_food_beff:
			food_name = "game1_icon_food_beff01.png";
			break;
		case e_food_shrimp:
			food_name = "game1_icon_food_shrimp01.png";
			break;
		case e_food_chil:
			food_name = "game1_icon_food_chili01.png";
			break;
		case e_food_egg:
			food_name = "game1_icon_food_egg01.png";
			break;
		case e_food_fish:
			food_name = "game1_icon_food_fish01.png";
			break;
		case e_food_pork:
			food_name = "game1_icon_food_pork01.png";
			break;
		case e_food_broccol:
			food_name = "game1_icon_food_broccoli01.png";
			break;
		case e_food_chicken:
			food_name = "game1_icon_food_chicken01.png";
			break;
		case e_food_mushrooms:
			food_name = "game1_icon_food_mushrooms01.png";
			break;
		default:
			food_name = "game1_icon_food_noodles01.png";
			break;
	}
	return food_name;
}

//制作食物
void GameScene::makeFood(Ref* pSender)
{
	if (chooose_food_num < 1)
	{
		return;
	}

	//配方
	int base_food[12];
	memset(base_food, 0, sizeof(base_food));
	base_food[0] = 1;
	base_food[1] = 1;
	bool is_true = isTureFood(base_food);
	
	clearFood();
	//上面
	Sprite* spr_noodle = Sprite::createWithSpriteFrameName(is_true ? "game1_icon_yangchunmian.png" : "game1_icon_orderbg.png");
	spr_noodle->setPosition(Vec2(1400, 330));
	this->addChild(spr_noodle);
	vec_noodle.push_back(spr_noodle);
}

//扔掉食材
void GameScene::ashcanFood(Ref* pSender)
{
	if (chooose_food_num < 1)
	{
		return;
	}
	clearFood();
}

//拉面秘籍
void GameScene::cookBook(Ref* pSender)
{

}
//电话
void GameScene::PhoneFood(Ref * pSender)
{
	comeCustomer();
}
//咖啡
void GameScene::chooseCake(Ref* pSender)
{
	Button* button = dynamic_cast<Button*>(pSender);
	if (button->isVisible())
	{
		Vec2 pos_cake = Vec2(200, 200);
		Sequence* seq = Sequence::create(MoveTo::create(0.3f, pos_cake), FadeOut::create(0.1f), NULL);
		button->runAction(seq);
	}
}
//判断食谱正确
bool GameScene::isTureFood(int base_food[12])
{
	bool is_true = true;
	for (int i = 0; i < 12; i++)
	{
		if (array_food[i] != base_food[i])
		{
			is_true = false;
			break;;
		}
	}
	return is_true;
}
//来顾客
void GameScene::comeCustomer()
{
	Node* tip_node = dynamic_cast<Node*>(rootNode->getChildByName("Tip"));
	Node* tip_node_1 = tip_node->getChildByTag(1);
	tip_node_1->setVisible(true);
	vec_customer_tip[1] = tip_node_1;
	vec_customer_time[1] = 60;
}
//清理案板
void GameScene::clearFood()//清除案板
{
	for (int i = 0; i < chooose_food_num; i++)
	{
		Sprite* spr_food = dynamic_cast<Sprite*>(rootNode->getChildByName("Board")->getChildByTag(i + 1));
		spr_food->setVisible(false);
	}
	memset(array_food, 0, sizeof(array_food));
	chooose_food_num = 0;
}

