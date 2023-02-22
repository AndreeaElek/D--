#include "Goblin.h"

Goblin::Goblin()
{
    setHP(60);
    setDamage(50);
    this->enemyType = EnemyType::Goblin;
}

Goblin::~Goblin()
{

}