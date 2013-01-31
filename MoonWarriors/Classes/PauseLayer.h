//
//  PauseLayer.h
//  MoonWarriorsx
//
//  Created by 王 磊 on 13-1-18.
//
//

#ifndef __MoonWarriorsx__PauseLayer__
#define __MoonWarriorsx__PauseLayer__

#include "cocos2d.h"
USING_NS_CC;

class PauseLayer : public CCLayerColor {
    
public:
    virtual bool init();
    virtual void  registerWithTouchDispatcher();
    
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);

//    void doPause();
    void doResume(CCObject *pSender);
    CREATE_FUNC(PauseLayer);
};


#endif /* defined(__MoonWarriorsx__PauseLayer__) */
