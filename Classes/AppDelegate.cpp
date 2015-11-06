#include "AppDelegate.h"
#include "GameScene.h"
#include "GameData.h"
#include "LoadingScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() 
{

}

AppDelegate::~AppDelegate() 
{
}

void AppDelegate::initGLContextAttrs()
{
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() 
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) 
	{
        glview = GLViewImpl::createWithRect("E-home-Noodle", Rect(0, 0, 1334, 750));
        director->setOpenGLView(glview);
    }

    director->getOpenGLView()->setDesignResolutionSize(1334, 750, ResolutionPolicy::SHOW_ALL);
    director->setDisplayStats(true);
    director->setAnimationInterval(1.0 / 60);

    FileUtils::getInstance()->addSearchPath("res");

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/GameScene.p;list");
	Json::getInstance()->readJson();

    auto scene = LoadingScene::createScene();
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() 
{
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() 
{
    Director::getInstance()->startAnimation();
}
