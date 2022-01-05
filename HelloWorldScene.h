#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"//bibliotheque de cocos2d
//declaration de classe helloworld
class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
	cocos2d::Sprite *mySprite;
	//declaration de la methode play
	void Play(Ref *pSender);
    
};

#endif // __HELLOWORLD_SCENE_H__
