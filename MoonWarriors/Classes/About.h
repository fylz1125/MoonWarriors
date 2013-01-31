//
//  About.h
//  MoonWarriorsx
//
//  Created by 王 磊 on 13-1-17.
//
//

#ifndef __MoonWarriorsx__About__
#define __MoonWarriorsx__About__

#include "cocos2d.h"
USING_NS_CC;

class About : public CCLayer {
    
public:
    static CCScene* scene();
    virtual bool init();
    void goBack();
    CREATE_FUNC(About);
    
};

#endif /* defined(__MoonWarriorsx__About__) */
