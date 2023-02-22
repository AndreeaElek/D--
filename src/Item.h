#ifndef ITEM_H
#define ITEM_H

#pragma once

#include <iostream>
#include <string>

class Item
{
public:
    Item();
    Item(std::string ItemName, std::string ItemType, int attackPower, int magicPower, int defencePower);
    ~Item();
    std::string getItemName()
    {
        return itemName;
    }
    int getAttackPower()
    {
        return this->attackPower;
    }
    int getDefencePower()
    {
        return this->defencePower;
    }
    int getMagicPower()
    {
        return this->magicPower;
    }
    std::string getItemType()
    {
        return this->itemType;
    }

private:
    int attackPower, magicPower, defencePower;
    std::string itemName, itemType;

};

#endif