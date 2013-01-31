//
//  Options.cpp
//  MoonWarriorsx
//
//  Created by 王 磊 on 13-1-18.
//
//

#include "Options.h"
#include "Resource.h"
#include "Config.h"
#include "StartMenu.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

CCScene* Options::scene()
{
    CCScene *scene = CCScene::create();
    Options *optionsLayer = Options::create();
    scene->addChild(optionsLayer);
    return scene;
}

bool Options::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite *sp = CCSprite::create(s_loading);
    sp->setAnchorPoint(CCPointZero);
    addChild(sp, 0, 1);
    
    CCTexture2D *imageCache = CCTextureCache::sharedTextureCache()->addImage(s_menuTitle);
    CCSprite *title = CCSprite::createWithTexture(imageCache, CCRectMake(0, 0, 134, 34));
    title->setPosition(ccp(winSize.width/2, winSize.height - 60));
    addChild(title);

    CCMenuItemFont *menuTitle = CCMenuItemFont::create("Sound");
    menuTitle->setFontName("Arial");
    menuTitle->setFontSize(18);
    menuTitle->setEnabled(false);
    
    CCMenuItemFont::setFontName("Arial");
    CCMenuItemFont::setFontSize(26);
    CCMenuItemToggle *toggle = CCMenuItemToggle::createWithTarget(this, menu_selector(Options::setOptions), CCMenuItemFont::create("On"),CCMenuItemFont::create("Off"), NULL);
    
    int selectId = Config::sharedConfig()->getAudioState()? 0 : 1;
    toggle->setSelectedIndex(selectId);
    
    CCLabelBMFont *backLb = CCLabelBMFont::create("Go Back", s_font);
    CCMenuItemLabel *goBack = CCMenuItemLabel::create(backLb, this, menu_selector(Options::goBack));
    goBack->setScale(0.6);
    CCActionInterval *fadeIn = CCFadeTo::create(1, 80);
    CCActionInterval *fadeOut = CCFadeTo::create(1, 255);
    CCEaseSineInOut *ease1 = CCEaseSineInOut::create(fadeIn);
    CCEaseSineInOut *ease2 = CCEaseSineInOut::create(fadeOut);
    CCFiniteTimeAction *seq = CCSequence::create(ease1, ease2, NULL);
    // 这里也是，参数必须强转，否则NDK编译不过
    goBack->runAction(CCRepeatForever::create((CCActionInterval*)seq));
    
    CCMenu *menu = CCMenu::create( menuTitle, toggle, goBack, NULL);
    menu->alignItemsInColumns(2,1);
    addChild(menu);

    
    CCPoint pos =  goBack->getPosition();
    pos.y -= 50;
    goBack->setPosition(pos);
    
    
    return true;
}

void Options::setOptions()
{
    bool tmpSound = Config::sharedConfig()->getAudioState();
    Config::sharedConfig()->updateAudioState(!tmpSound);
    
    if (Config::sharedConfig()->getAudioState()) {
        SimpleAudioEngine::sharedEngine()->resumeAllEffects();
        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    }else{
        SimpleAudioEngine::sharedEngine()->pauseAllEffects();
        SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    }
    
}

void Options::goBack(cocos2d::CCObject *pSender)
{
    CCScene *scene = StartMenu::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2, scene));

}


