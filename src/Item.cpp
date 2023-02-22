#include "Item.h"

Item::Item()
{

}

Item::Item(std::string itemName, std::string itemType, int attackPower, int magicPower, int defencePower)
{
    this->itemName = itemName;
    this->itemType = itemType;
    this->attackPower = attackPower;
    this->magicPower = magicPower;
    this->defencePower = defencePower;
}

Item::~Item()
{

}