#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <SFML/Audio.hpp>

#include "Player.h"
#include "Wizard.h"
#include "Warrior.h"
#include "Rogue.h"
#include "Enemy.h"
#include "Orc.h"
#include "Goblin.h"
#include "Troll.h"

bool restartGame();

bool introScene(); 

Player* setupPlayer();

void roadsScene();
bool chestScene();

Enemy* generateRandomEnemy();
bool battleScene(Player* player, Enemy* enemy);