//
//  Config.cpp
//  MoonWarriorsx
//
//  Created by 王 磊 on 13-1-14.
//
//

#include "Config.h"

CCArray *play_bullet;
CCArray *enemy_bullet;
CCArray *enemy_items;

static  Config *g_config = NULL;

/**这里用的单例做的全局参数。JS版的直接就定义了一堆全局数组，真是方便*/
Config::Config():m_scoreValue(0),m_life(3),m_isAudioOn(true)
{
    CCAssert(g_config == NULL, "Attempted to allocate a second instance of a singleton.");
    EnemyInfo temp;
    temp.showType = "Repeate";
    temp.showTime = 2;
    temp.types[1] = 1;
    temp.types[2] = 2;
    m_enemies.push_back(temp);
    
    temp.showTime = 5;
    temp.types[0] = 3;
    temp.types[1] = 4;
    temp.types[2] = 5;
    m_enemies.push_back(temp);
    
    EnemyType enemyType;
    enemyType.type = 0;
    enemyType.textureName = "E0.png";
    enemyType.bulletType = "W2.png";
    enemyType.hp = 1;
    enemyType.moveType = 0;
    enemyType.scoreValue = 15;
    m_enemyTypes.push_back(enemyType);
    
    enemyType.type = 1;
    enemyType.textureName = "E1.png";
    enemyType.bulletType = "W2.png";
    enemyType.hp = 2;
    enemyType.moveType = 0;
    enemyType.scoreValue = 40;
    m_enemyTypes.push_back(enemyType);
    
    enemyType.type = 2 ;
    enemyType.textureName = "E2.png";
    enemyType.bulletType = "W2.png";
    enemyType.hp = 4;
    enemyType.moveType = 2;
    enemyType.scoreValue = 60;
    m_enemyTypes.push_back(enemyType);
    
    enemyType.type = 3;
    enemyType.textureName = "E3.png";
    enemyType.bulletType = "W2.png";
    enemyType.hp = 6;
    enemyType.moveType = 3;
    enemyType.scoreValue = 80;
    m_enemyTypes.push_back(enemyType);
    
    enemyType.type = 4;
    enemyType.textureName = "E4.png";
    enemyType.bulletType = "W2.png";
    enemyType.hp = 10;
    enemyType.moveType = 2;
    enemyType.scoreValue = 150;
    m_enemyTypes.push_back(enemyType);
    
    enemyType.type = 5;
    enemyType.textureName = "E5.png";
    enemyType.bulletType = "W2.png";
    enemyType.hp = 15;
    enemyType.moveType = 2;
    enemyType.scoreValue = 200;
    m_enemyTypes.push_back(enemyType);
    
    
}
Config::~Config()
{
    play_bullet->release();
    enemy_bullet->release();
    enemy_items->release();
    enemy_items = NULL;
    play_bullet = NULL;
    enemy_bullet = NULL;
    CCLOG("release config");

}

Config* Config::sharedConfig()
{
    if (!g_config) {
        g_config = new Config();
    }
    return g_config;
}

vector<EnemyInfo> Config::getEnemise()
{
    return m_enemies;
}

vector<EnemyType> Config::getEnemyType()
{
    return m_enemyTypes;
}

int Config::getScoreValue()
{
    return m_scoreValue;
}

void Config::setScoreValue(int score)
{
    m_scoreValue += score;
}

int Config::getLifeCount()
{
    return m_life;
}
void Config::updateLifeCount()
{
    m_life--;
}

bool Config::getAudioState()
{
    return m_isAudioOn;
}

void Config::updateAudioState(bool isOn)
{
    m_isAudioOn = isOn;
}

void Config::resetConfig()
{
    m_scoreValue = 0;
    m_life = 3;
//    m_isAudioOn = true;
}
