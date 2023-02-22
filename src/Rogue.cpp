#include "Rogue.h"

Rogue::Rogue(std::string name):Player(name)
{
    setHealth(60);
    setDamage(30);
    this->playerType = PlayerType::Rogue;
}

Rogue::Rogue()
{
    
}

Rogue::~Rogue()
{

}

/*void Rogue::Attack()
{
    std::cout<<"I'm a Rogue, and I'm attacking"<<std::endl;
}*/