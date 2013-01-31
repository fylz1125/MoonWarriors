//
//  Config.h
//  MoonWarriorsx
//
//  Created by 王 磊 on 13-1-5.
//
//

#ifndef MoonWarriorsx_Config_h
#define MoonWarriorsx_Config_h

#include "cocos2d.h"
#include <vector>

USING_NS_CC;
using namespace std;

extern cocos2d::CCArray *play_bullet;
extern cocos2d::CCArray *enemy_bullet;
extern cocos2d::CCArray *enemy_items;

typedef struct Enemies
{
    string showType;
    int showTime;
    int types[3];
    Enemies()
    {
        showType = "Repeate";
        showTime = 0;
        types[0] = 0;
        types[1] = 0;
        types[2] = 0;
        
    }
}EnemyInfo;

typedef struct {
    int type;
    string textureName;
    string bulletType;
    int hp;
    int moveType;
    int scoreValue;
}EnemyType;

class Config : public CCObject{
private:
    vector<EnemyInfo> m_enemies;
    vector<EnemyType> m_enemyTypes;
    int m_scoreValue;
    int m_life;
    bool m_isAudioOn;
    Config();
public:
    ~Config();
    static Config* sharedConfig();
    vector<EnemyInfo> getEnemise();
    vector<EnemyType> getEnemyType();
    int getLifeCount();
    bool getAudioState();
    void updateAudioState(bool isOn);
    int getScoreValue();
    void updateLifeCount();
    void setScoreValue(int score);
    void resetConfig();
};


#endif
