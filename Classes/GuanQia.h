
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocostudio::timeline;
using namespace ui;
class GuanQiaLayer : public cocos2d::Layer
{
public:
	virtual bool init();
	CREATE_FUNC(GuanQiaLayer);
	GuanQiaLayer();
	~GuanQiaLayer();

	void exit(Ref * pSender);

private:

};

