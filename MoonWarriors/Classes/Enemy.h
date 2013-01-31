//
//  Enemy.h
//  MoonWarriorsx
//
//  Created by 王 磊 on 13-1-14.
//
//

#ifndef __MoonWarriorsx__Enemy__
#define __MoonWarriorsx__Enemy__

#include "cocos2d.h"
#include "Config.h"
#include "UnitSprite.h"

USING_NS_CC;

class Enemy : public UnitSprite {
private:
    bool m_active;
    int m_speed;
    int m_bulletSpeed;
    int m_HP;
    int m_bulletPowerValure;
    int m_moveType;
    int m_scoreValue;
    int m_zOrder;
    float m_delayTime;
    int m_attackMode;
    
public:
    Enemy();
    ~Enemy();
    bool enemyInit(EnemyType type);
    virtual void update(float dt);
    void shoot();
    virtual void hurt();
    virtual void destroy();
    virtual CCRect collideRect();
    virtual bool isActive();
    
    static void sharedEnemy();
    static Enemy* create(EnemyType type);
    int getMoveType();
    
};
#endif /* defined(__MoonWarriorsx__Enemy__) */
