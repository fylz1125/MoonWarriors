//
//  About.cpp
//  MoonWarriorsx
//
//  Created by 王 磊 on 13-1-17.
//
//

#include "About.h"
#include "Resource.h"
#include "StartMenu.h"

CCScene* About::scene()
{
    CCScene *scene = CCScene::create();
    About *about = About::create();
    scene->addChild(about);
    return scene;
}

bool About::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite *sp = CCSprite::create(s_loading);
    sp->setAnchorPoint(ccp(0, 0));
    addChild(sp, 0, 1);
    
    CCTexture2D *imageCache = CCTextureCache::sharedTextureCache()->addImage(s_menuTitle);
    CCSprite *title = CCSprite::createWithTexture(imageCache, CCRectMake(0, 36, 100, 34));
    title->setPosition(ccp(winSize.width/2, winSize.height - 60));
    addChild(title);
    
    CCLabelTTF *about = CCLabelTTF::create("   I recode this game according to the logic of MoonWarriors-html5,almost all of the code  keep unanimous with the original. \n     This showcase utilizes many features from Cocos2d-x engine, including: Parallax background, tilemap, actions, ease, frame animation, schedule, Labels, keyboard Dispatcher, Scene Transition", "Arial", 18, CCSizeMake(winSize.width * 0.85, 320), kCCTextAlignmentLeft);
    about->setPosition(ccp(winSize.width / 2, winSize.height / 2 - 20));
    about->setAnchorPoint(ccp(0.5, 0.5));
    addChild(about);
    
    
    CCLabelBMFont *backLb = CCLabelBMFont::create("Go Back", s_font);
    CCMenuItemLabel *goBack = CCMenuItemLabel::create(backLb, this, menu_selector(About::goBack));
    goBack->setScale(0.6);
    CCActionInterval *fadeIn = CCFadeTo::create(1, 80);
    CCActionInterval *fadeOut = CCFadeTo::create(1, 255);
    CCEaseSineInOut *ease1 = CCEaseSineInOut::create(fadeIn);
    CCEaseSineInOut *ease2 = CCEaseSineInOut::create(fadeOut);
    CCFiniteTimeAction *seq = CCSequence::create(ease1, ease2, NULL);
    // 参数必须要强转，不然ndk编译不过
    goBack->runAction(CCRepeatForever::create((CCActionInterval*)seq));
    
    CCMenu *menu = CCMenu::create(goBack, NULL);
    menu->setPosition(winSize.width / 2, 50);
    addChild(menu);
    
    return  true;
}

void About::goBack()
{
    CCScene *scene = StartMenu::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2, scene));
}

