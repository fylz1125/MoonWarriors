//
//  GameOver.h
//  MoonWarriorsx
//
//  Created by 王 磊 on 13-1-16.
//
//

#ifndef __MoonWarriorsx__GameOver__
#define __MoonWarriorsx__GameOver__

#include "cocos2d.h"

USING_NS_CC;

class GameOver : public CCLayer {
    
public:

    virtual bool init();
    static CCScene * scene();
    void playAgain();
    CREATE_FUNC(GameOver);
};

#endif /* defined(__MoonWarriorsx__GameOver__) */
