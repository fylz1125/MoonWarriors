//
//  GameLayer.h
//  MoonWarriorsx
//
//  Created by 王 磊 on 12-12-29.
//
//

#ifndef __MoonWarriorsx__GameLayer__
#define __MoonWarriorsx__GameLayer__

#include "cocos2d.h"
#include "Ship.h"
#include "LevelManager.h"
USING_NS_CC;

enum Sate{
    statePlaying = 0,
    stateGameOver= 1,
};


class GameLayer : public CCLayer {
    
private:
    int m_state;
    int m_time;
    CCSize winSize;
    Ship *m_ship;
    CCSprite * m_backSky;
    float m_backSkyHeight;
    CCSprite *m_backSkyRe;
    CCTMXTiledMap *m_backTileMap;
    float m_backTileMapHeight;
    CCTMXTiledMap *m_backTileMapRe;
    bool m_isBackSkyReload;
    bool m_isBackTileReload;
    CCLabelBMFont *m_lbScore;
    CCLabelTTF *m_lifeCount;
    CCRect m_screenRec;
    LevelManager *m_levelManager;
    int m_tempScore;
public:
    GameLayer();
    ~GameLayer();
    virtual bool init();
    virtual void update(float dt);
    void scoreCounter();
    Ship* getShip();
    void checkIsCollide();
    void removeInactiveUnit(float dt);
    void checkIsReborn();
    bool collide(UnitSprite *a, UnitSprite *b);
    void updateUI();
    void gameOver();
    void doPause(CCObject *pSender);
    virtual void onEnter();
    virtual void onExit();
    void initBackground();
    void movingBackground();
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
    CREATE_FUNC(GameLayer);
};

#endif /* defined(__MoonWarriorsx__GameLayer__) */
