//
//  LevelManager.cpp
//  MoonWarriorsx
//
//  Created by 王 磊 on 13-1-14.
//
//

#include "LevelManager.h"
#include "Enemy.h"
#include "GameLayer.h"

using namespace cocos2d;

LevelManager::LevelManager(CCLayer *gameLayer)
{
    CCAssert(gameLayer != NULL, "game layer must be non-null");
    m_gameLayer = gameLayer;
    m_enemies = Config::sharedConfig()->getEnemise();
    m_enemyType = Config::sharedConfig()->getEnemyType();

}
LevelManager::~LevelManager()
{
    
}



void LevelManager::loadLevelResource(int dt)
{
    for (vector<EnemyInfo>::iterator iter = m_enemies.begin(); iter != m_enemies.end(); ++iter) {
        if (iter->showType == "Repeate") {
            if (dt % iter->showTime == 0) {
                // 数组长度
                for (int i = 0; i != 3; ++i) {
                    addEnemyToGameLayer(iter->types[i]);
                }
            }
        }
    }
}



void LevelManager::addEnemyToGameLayer(int type)
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    EnemyType enemyType = m_enemyType[type];
    Enemy * enemy = Enemy::create(enemyType);
    
    CCPoint enemyPos = ccp( 80 + (winSize.width - 160) * CCRANDOM_0_1(), winSize.height);
    CCSize eSize = enemy->getContentSize();
    enemy->setPosition(enemyPos);
    
    CCPoint offset; //= ((GameLayer*)m_gameLayer)->getShip()->getPosition();
    CCAction *tempAction; //= CCMoveTo::create(1, offset);
    CCMoveBy *a0;
    CCMoveBy *a1;
    CCCallFuncN *onComplete;
    
    switch (enemy->getMoveType()) {
        case 0:
            if (((GameLayer*)m_gameLayer)->getShip()) {
                offset = ((GameLayer*)m_gameLayer)->getShip()->getPosition();
            }else{
                offset = ccp(winSize.width / 2, 0);
            }
            tempAction = CCMoveTo::create(1, offset);
            break;
            
        case 1:
            offset = ccp(0, -winSize.height - eSize.height);
            tempAction = CCMoveBy::create(4, offset);
            break;
            
        case 2:
            offset = ccp(0, -100 - 200 * CCRANDOM_0_1());
            a0 = CCMoveBy::create(0.5, offset);
            a1 = CCMoveBy::create(1, ccp(-50 - 100 * CCRANDOM_0_1(), 0));
            
            onComplete =  CCCallFuncN::create(enemy, callfuncN_selector(LevelManager::repeatAction));
            tempAction = CCSequence::create(a0, a1, onComplete, NULL);
            break;
            
        case 3:
            int newX = (enemyPos.x <= winSize.width / 2 ) ? 320 : - 320;
            a0 = CCMoveBy::create(4, ccp(newX, -240));
            a1 = CCMoveBy::create(4, ccp(-newX, -320));
            tempAction = CCSequence::create(a0, a1, NULL);
            break;
    
    }
    

    
    
    m_gameLayer->addChild(enemy,enemy->getZOrder(), 1000);
    enemy_items->addObject(enemy);
    enemy->runAction(tempAction);
}

void LevelManager::repeatAction(CCNode *pSender)
{
    CCDelayTime *delay =  CCDelayTime::create(1);
    CCMoveBy *mv = CCMoveBy::create(1, ccp(100 + 100 * CCRANDOM_0_1(), 0));
    CCFiniteTimeAction *seq = CCSequence::create(delay, mv, delay->copy(), mv->reverse(), NULL);
    pSender->runAction(CCRepeatForever::create((CCActionInterval*)seq));
}
