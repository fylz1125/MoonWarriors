//
//  GameOver.cpp
//  MoonWarriorsx
//
//  Created by 王 磊 on 13-1-16.
//
//

#include "GameOver.h"
#include "Resource.h"
#include "Config.h"
#include "SimpleAudioEngine.h"
#include "GameLayer.h"

CCScene* GameOver::scene()
{
    CCScene *scene = CCScene::create();
    GameOver *gameOver = GameOver::create();
    scene->addChild(gameOver);
    return  scene;
    
}

bool GameOver::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite *sp = CCSprite::create(s_loading);
    sp->setAnchorPoint(ccp(0, 0));
    addChild(sp, 0, 1);
    
    CCSprite *logo = CCSprite::create(s_gameOver);
    logo->setAnchorPoint(ccp(0, 0));
    logo->setPosition(ccp(0, 300));
    addChild(logo, 10, 1);
    
    CCSprite *playAgainNormal = CCSprite::create(s_menu, CCRectMake(378, 0, 126, 33));
    CCSprite *playAgainSelected = CCSprite::create(s_menu, CCRectMake(378, 33, 126, 33));
    CCSprite *playAgainDisabled = CCSprite::create(s_menu, CCRectMake(378, 33*2, 126, 33));
    
    CCSprite *cocos2dx = CCSprite::create(s_cocos2dx);
    cocos2dx->setPosition(ccp(160, 150));
    addChild(cocos2dx, 10);
    
    CCMenuItemSprite *playAgain = CCMenuItemSprite::create(playAgainNormal, playAgainSelected, playAgainDisabled, this,
                                                           menu_selector(GameOver::playAgain));
    
    CCMenu *menu = CCMenu::create(playAgain, NULL);
    addChild(menu, 1, 2);
    menu->setPosition(winSize.width / 2, 220);
    
    int tempScore = Config::sharedConfig()->getScoreValue();
    char score[20];
    char s[] = "Your score:";
    sprintf(score, "%d", tempScore);
    CCLabelTTF *lb = CCLabelTTF::create(strcat(s, score), "Arial Bold", 16);
    lb->setPosition(ccp(160, 280));
    lb->setColor(ccc3(250, 179, 0));
    addChild(lb, 10);
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(s_mainMainMusic, true);
    
    return true;
    
}

void GameOver::playAgain()
{
    CCScene *scene = CCScene::create();
    scene->addChild(GameLayer::create());
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2, scene));
}
