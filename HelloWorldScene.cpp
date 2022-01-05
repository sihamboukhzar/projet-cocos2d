

#include "HelloWorldScene.h"
#include "NewScene.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	//size
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	//l'image de plan d'arrier
	mySprite = Sprite::create("BackGround.png");
	//la position de l'image
	mySprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2)+120 + origin.y));
	//ajout de fils(l'image)
	this->addChild(mySprite);
	//declaration des elements du menu
	auto menu_item_1 = MenuItemImage::create("Play.png","Play.png", CC_CALLBACK_1(HelloWorld::Play, this));
	auto menu_item_4 = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	//la visibilite de ces elements  dans la sortie
	menu_item_1->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 2));
	menu_item_4->setPosition(Point((visibleSize.width / 2)+400, (visibleSize.height / 5)-50 * 1));
	//declaration de menu 
	auto *menu = Menu::create(menu_item_1, menu_item_4, NULL);
	menu->setPosition(Point(0, 0));
	this->addChild(menu);

	//si layer herite de init retorne tous ca 
	return true;
}
//definition de la methode play
void HelloWorld::Play(cocos2d::Ref *pSender)
{
	CCLOG("IMAGE Button");
	auto scene = NewScene::createScene();
	Director::getInstance()->pushScene(scene);
}
//defintion de la methode menuCloseCallback
void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
