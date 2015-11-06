#ifndef BARDATA_H
#define BARDATA_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "EnmuResource.h"
USING_NS_CC;

class BarData:public Layer
{
public:
	BarData();
	~BarData();
	CREATE_FUNC(BarData);

	CC_SYNTHESIZE(int,m_Level,LevelNum);
	CC_SYNTHESIZE(int,m_time,TimeNum);
	CC_SYNTHESIZE(int,m_smile,SmileNum);
	CC_SYNTHESIZE(int,m_money,Money);
	CC_SYNTHESIZE(int,m_angry,Angry);
protected:
private:
};
#endif
