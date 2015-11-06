#include "GameScene.h"

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
	map_customer.clear();
	vec_customer.clear();
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
	//角色心情提示
	for (int i = 0; i < MAX_CUSTOMER; i++)
	{
		Node* customer_node = dynamic_cast<Node*>(rootNode->getChildByName("Customer")->getChildByTag(i + 1));
		vec_customer.push_back(customer_node);
	}
	this->scheduleUpdate();
    return true;
}

//食材篮选择食材
void GameScene::chooseFood(Ref* pSender)
{
	Button* button = dynamic_cast<Button*>(pSender);
	int foodTag = button->getTag();
	if (array_food[foodTag] == 1 || chooose_food_num >= MAX_CHOOSE_FOOD)
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
		itr->setPositionX(itr->getPositionX() - MOVE_SPEED);
	}
	//面条		
	for (std::vector<Noodle*>::iterator itr = vec_noodle.begin(); itr != vec_noodle.end();)
	{
		bool is_noodle_none = false;
		if ((*itr)->getPositionX() <= -60)
		{
			is_noodle_none = true;
		}
		else
		{
			(*itr)->setPositionX((*itr)->getPositionX() - MOVE_SPEED);
			if ((*itr)->getNoodleState())//面条是制作成功的
			{
				for (int i = 0; i < MAX_CUSTOMER; i++)
				{
					if (map_customer[i] && map_customer[i]->isAbelEat())
					{
						float pos = (*itr)->getPositionX() - vec_customer[i]->getPositionX() - 667;
						if (pos < 64 && pos > -64)
						{
							is_noodle_none = true;
							map_customer[i]->setStateEating();//顾客吃了，换状态
						}
					}
				}
			}
		}
		if (is_noodle_none)
		{
			this->removeChild((*itr));
			itr = vec_noodle.erase(itr);
		}
		else
		{
			itr++;
		}
	}
	//顾客
	for (int i = 0; i < MAX_CUSTOMER; i++)
	{
		if (map_customer[i])//顾客存在
		{
			if (map_customer[i]->spendTime(delta))
			{
				//删除顾客
				this->removeChild(map_customer[i]);
				map_customer[i] = nullptr;
			}
		}
		else
		{
			struct_MAN* struct_man = Json::getInstance()->getNewCustomer();
			if (struct_man)
			{
				createNewCustomer(i, struct_man);
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

	int noodle_id = Json::getInstance()->getNoodlesID(array_food);
	
	clearFood();
	//上面
	Noodle* noodle = Noodle::createNoodle(noodle_id);
	noodle->setPosition(Vec2(1400, 350));
	this->addChild(noodle);
	vec_noodle.push_back(noodle);
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
//来顾客
void GameScene::createNewCustomer(int nNum, struct_MAN* struct_man)
{
	if (nNum > MAX_CUSTOMER - 1 || nNum < 0)
	{
		return;
	}
	Customer* customer = Customer::createCustomer(vec_customer[nNum], struct_man);
	this->addChild(customer);

	map_customer[nNum] = customer;
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

