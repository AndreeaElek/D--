#include "Player.h"

Player::Player()
{

}

Player::Player(std::string name)
{
    this->name = name;
}

Player::~Player()
{

}

int Player::Attack()
{
    int playerAttackPower = this->getDamage() + this->getItemsAttackPower();
    return playerAttackPower;
}

void Player::CheckInventory()
{
    if(inventory.empty())
    {
        std::cout<<"Your inventory is empty \n";
    }
    else
    {
        std::cout<<"Items in your inventory: ";
        for(auto& item : inventory)
        {
            std::cout<<item->getItemName()<<"; ";
        }
        std::cout<< std::endl;
    }
    std::cout << "Press any key to continue..." << std::endl;
    _getch();
    system("cls");
}

void Player::CreateChestItem()
{
    switch (this->playerType)
    {
        case PlayerType::Wizard:
        {
            Item* wand = new Item("Wand", "attack",5,15,0);
            this->inventory.push_back(wand);
            std::cout<<"Wand added to inventory \n";
            break;
        }
        case PlayerType::Warrior:
        {
            Item* shield = new Item("Shield","defence",0,0,15);
            this->inventory.push_back(shield);
            std::cout<<"Shield added to inventory \n";
            break;
        }
        case PlayerType::Rogue:
        {
            Item* knife = new Item("Knife", "attack",15,0,0);
            this->inventory.push_back(knife);
            std::cout<<"Knife added to inventory \n";
            break;
        }
    }
}

int Player::getItemsAttackPower()
{
    int totalItemsDamage=0;
    if(!(inventory.empty()))
    {
        for(auto& item : inventory)
        {
            if(item->getItemType() == "attack")
            {
                totalItemsDamage += item->getAttackPower();
            }
        }
    }
    return totalItemsDamage;
}

int Player::getItemsDefencePower()
{
    int totalItemsDefence=0;
    if(!(inventory.empty()))
    {
        for(auto& item : inventory)
        {
            if(item->getItemType() == "defence")
            {
                totalItemsDefence += item->getDefencePower();
            }
        }
    }
    return totalItemsDefence;    
}

int Player::getItemsMagicPower()
{
    int totalItemsMagic=0;
    if(!(inventory.empty()))
    {
        for(auto& item : inventory)
        {
            if(item->getItemType() == "magic")
            {
                totalItemsMagic += item->getMagicPower();
            }
        }
    }
    return totalItemsMagic;
}

void Player::DeleteItems()
{
    if(!(inventory.empty()))
    {
        for(auto& item : inventory)
        {
            delete item;
        }
    }
    inventory.clear();
}


