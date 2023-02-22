#include "Warrior.h"

Warrior::Warrior(std::string name):Player(name)
{
    setHealth(50);
    setDamage(70);
    this->playerType = PlayerType::Warrior;
}

Warrior::Warrior()
{
    
}

Warrior::~Warrior()
{

}

/*void Warrior::Attack()
{
    std::cout<<"I'm a Warrior and I'm attacking"<<std::endl;
}*/