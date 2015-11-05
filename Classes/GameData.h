#pragma once

#include "cocos2d.h"
USING_NS_CC;
class GameData : public Ref
{
public:
	static GameData* getInstance();
	void readData();
	void createData();
	void saveData();
};

