//
//  Bullet.cpp
//  MoonWarriorsx
//
//  Created by 王 磊 on 13-1-3.
//
//

#include "Bullet.h"
#include "Resource.h"
#include "Config.h"


Bullet::Bullet():m_active(true),m_velocityx(0),m_velocityy(200),m_power(1),m_Hp(1),m_zorder(3000)
{
    
}
/**子弹构造器，可以用create重写下，懒的写了*/
Bullet::Bullet(int speed, const char *weapon, int attactMode)
{
    m_active = true;
    m_velocityx = 0;
    m_power = 1;
    m_Hp = 1;
    m_zorder = 3000;
    
    m_velocityy = -speed;
    m_attackMode = attactMode;
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(s_bullet_plist);
    this->initWithSpriteFrameName(weapon);
    ccBlendFunc cbl = {GL_SRC_ALPHA, GL_ONE};
    this->setBlendFunc(cbl);

}

void Bullet::update(float dt)
{


    CCPoint position = this->getPosition();
    position.x -= m_velocityx * dt;
    position.y -= m_velocityy * dt;
    setPosition(position);
    if (m_Hp <= 0) {
        m_active = false;
    }
}
bool Bullet::init()
{
    return true;
}

void Bullet::hurt()
{
    m_Hp--;
}

void Bullet::destroy()
{
    
    // 子弹爆炸特效
    CCSprite *explode = CCSprite::create(s_hit);
    ccBlendFunc cb = {GL_SRC_ALPHA, GL_ONE };
    explode->setBlendFunc(cb);
    explode->setPosition(this->getPosition());
    explode->setRotation(CCRANDOM_0_1() * 360);
    explode->setScale(0.75);
    getParent()->addChild(explode, 9999);

    play_bullet->removeObject(this);
    enemy_bullet->removeObject(this);
    this->removeFromParent();
    
    CCCallFuncN *removeExplode =  CCCallFuncN::create(explode, callfuncN_selector(Bullet::removeExplode));
    explode->runAction(CCScaleBy::create(0.3, 2, 2));
    explode->runAction(CCSequence::create(CCFadeOut::create(0.3), removeExplode, NULL));
    
}

void Bullet::removeExplode(CCNode *pSender)
{
    pSender->removeFromParent();
}
bool Bullet::isActive()
{
    return m_active;
}

CCRect Bullet::collideRect()
{
    CCPoint pos = this->getPosition();
    return CCRectMake(pos.x - 3, pos.y - 3, 6, 6);
}