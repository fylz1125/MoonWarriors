//
//  UnitSprite.h
//  MoonWarriorsx
//
//  Created by 王 磊 on 13-1-15.
//
//

#ifndef __MoonWarriorsx__UnitSprite__
#define __MoonWarriorsx__UnitSprite__

#include "cocos2d.h"
USING_NS_CC;


class CostomeKeyPadDelegae : public CCKeypadDelegate , public CCNode{
    
public:
    virtual void keyBackClicked();
};


class UnitSprite : public CCSprite{
    
public:
    UnitSprite();
    ~UnitSprite();
    virtual void destroy() = 0;
    virtual void hurt() = 0 ;
    virtual CCRect collideRect() = 0;
    virtual bool isActive() = 0;
};

#endif /* defined(__MoonWarriorsx__UnitSprite__) */
