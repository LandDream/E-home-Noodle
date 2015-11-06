#pragma once

#include "cocos2d.h"
#include "EnmuResource.h"
USING_NS_CC;
class Noodle : public Node
{
public:
	Noodle();
	~Noodle();
	CREATE_FUNC(Noodle);
	static Noodle* createNoodle(int nID);
	void setNoodleTpye(int nID);
	int noodle_id;
	CC_SYNTHESIZE(bool, b_noodle_state, NoodleState);
};

