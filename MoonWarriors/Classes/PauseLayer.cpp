//
//  PauseLayer.cpp
//  MoonWarriorsx
//
//  Created by 王 磊 on 13-1-18.
//
//

#include "PauseLayer.h"
#include "SimpleAudioEngine.h"
#include <limits>

using namespace CocosDenshion;

CCMenu *menu;
bool PauseLayer::init()
{
    // 擦哦，ccc4的最后一个参数才是透明度，有点坑
    if (!CCLayerColor::initWithColor(ccc4(0, 0, 0, 100))) {
        return  false;
    }
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    // 开启触控
    setTouchEnabled(true);
    CCMenuItemImage *play = CCMenuItemImage::create("play.png", "play.png");
    play->setAnchorPoint(ccp(1, 0));
    play->setTag(10);
    play->setPosition(ccp(winSize.width, 0));
    
    
    menu = CCMenu::create(play, NULL);
    menu->setAnchorPoint(ccp(0, 0));
    addChild(menu, 1, 10);
    menu->setPosition(CCPointZero);
    
    return true;
}

// 触摸被吞掉了，这个回调不会调用哦
void PauseLayer::doResume(CCObject *pSender)
{
    CCLog("resume!");
}

void PauseLayer::registerWithTouchDispatcher()
{
    // NDK编译，需加上头 #include <limits>
    // 优先级数字设为最小，那么具有最高优先级，最后参数设为true，则触摸会被这里吞掉，下面的层不会接收到触摸事件
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, (std::numeric_limits<int>::min()), true);
    CCLayer::registerWithTouchDispatcher();
}

bool PauseLayer::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    // 因为回调调不到了，所以resume写在了这里
    CCRect rect =  menu->getChildByTag(10)->boundingBox();
    if (rect.containsPoint(touch->getLocation())) {
        CCLog("touch play");
        CCDirector::sharedDirector()->resume();
        SimpleAudioEngine::sharedEngine()->resumeAllEffects();
        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
        removeFromParent();
    }
    return true;
}
void PauseLayer::ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    
}
void PauseLayer::ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    
}
