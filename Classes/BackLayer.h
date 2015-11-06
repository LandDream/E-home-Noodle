#ifndef _SETLAYER_H
#define _SETLAYER_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "EnmuResource.h"
#include "Customer.h"
#include "Noodle.h"
#include "Json.h"
USING_NS_CC;
using namespace ui;
class BackLayer : public Layer
{
public:
	BackLayer();
	~BackLayer();
	virtual bool init();

	CREATE_FUNC(BackLayer);
protected:
private:
	void CloseCallBack(Ref * pSender);
	void BackCallBack(Ref * pSender);

};
#endif