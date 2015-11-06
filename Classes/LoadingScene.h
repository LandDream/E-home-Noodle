#ifndef LOADINGSCENE_H
#define LOADINGSCENE_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "EnmuResource.h"
#include "Customer.h"
USING_NS_CC;

class LoadingScene : public Layer
{
public:
	LoadingScene();
	~LoadingScene();

	static Scene * createScene();
	virtual bool init();

	void GoMainScene(float d);
	CREATE_FUNC(LoadingScene);
protected:
private:
};
#endif