#include "Wizard.h"

Wizard::Wizard(std::string name):Player(name)
{
    setHealth(70);
    setDamage(80);
    this->playerType = PlayerType::Wizard;
}

Wizard::Wizard()
{
    
}

Wizard::~Wizard()
{

}

/*void Wizard::Attack()
{
    std::cout<<"I'm a Wizard, and I'm attacking"<<std::endl;
}*/