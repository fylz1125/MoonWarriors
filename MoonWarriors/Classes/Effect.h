//
//  Effect.h
//  MoonWarriorsx
//
//  Created by 王 磊 on 12-12-29.
//
//

#ifndef __MoonWarriorsx__Effect__
#define __MoonWarriorsx__Effect__

#include "cocos2d.h"
USING_NS_CC;

class Effect : public cocos2d::CCNode
{
    
private:
    CCSprite *m_sprite;
    
public:
    Effect(void);
    ~Effect(void);
    
    // flare effect
    void flareEffect(CCNode* parent, CCCallFunc* callback);
    void explode(CCNode *parent, CCPoint pos);
    void spark(CCPoint pos, CCNode *parent, float scale, float duration);
    
    void killSprite(CCNode *pSender);

    
    
    static void sharedExplosion();
    static Effect* create();
    
};
#endif /* defined(__MoonWarriorsx__Effect__) */
