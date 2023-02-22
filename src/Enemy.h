#ifndef ENEMY_H
#define ENEMY_H

#pragma once

#include <string>
#include <iostream>

enum class EnemyType 
{
    Orc,
    Goblin,
    Troll
};

class Enemy
{
public:
    EnemyType enemyType;

    Enemy();
    ~Enemy();
    void setHP(int HP)
    {
        this->HP = HP;
    }
    int getHP()
    {
        return this->HP;
    }
    void setDamage(int damage)
    {
        this->damage = damage;
    }
    int getDamage()
    {
        return this->damage;
    }

private:
    int HP, damage;

};

#endif