//
//  Options.h
//  MoonWarriorsx
//
//  Created by 王 磊 on 13-1-18.
//
//

#ifndef __MoonWarriorsx__Options__
#define __MoonWarriorsx__Options__

#include "cocos2d.h"
USING_NS_CC;

class Options : public CCLayer {
    
public:
    static CCScene* scene();
    void setOptions();
    void goBack(CCObject *pSender);
    virtual bool init();
    CREATE_FUNC(Options);
    
};

#endif /* defined(__MoonWarriorsx__Options__) */
