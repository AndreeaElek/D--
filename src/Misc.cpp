#include "Misc.h"

bool introScene()
{
    /*sf::Music music1;
    music1.openFromFile("Main_Menu.wav");
    music1.setVolume(40);
    music1.play();*/
    bool validAnswer = false, answerValue;
    int answer;
    std::cout<<"This is the intro text for the game" << std::endl;
    while(validAnswer==false)
    {
        std::cout<<"Do you want to play?" << std::endl 
                    << "1. Yes" << std::endl 
                    << "2. No" << std::endl;
        std::cin>>answer;
        
        system("cls");
        if(answer == 1)
        {
            answerValue =true;
            validAnswer = true;
        }
        else if(answer == 2)
        {
            answerValue = false;
            validAnswer = true;
        }
        else
        {
            std::cout<<"Wrong input. Please pick a valid option" << std::endl;
        }
    }
    //music1.stop();
    return answerValue;
}

bool restartGame()
{
    /*sf::Music music1;
    music1.openFromFile("Main_Menu.wav");
    music1.setVolume(40);
    music1.play();*/
    bool validAnswer = false, answerValue;
    int answer;
    
    while(validAnswer==false)
    {
        std::cout<<"Do you want to restrart the game?" << std::endl 
                    << "1. Yes" << std::endl 
                    << "2. No" << std::endl;
        std::cin>>answer;
        
        system("cls");
        if(answer == 1)
        {
            answerValue =true;
            validAnswer = true;
        }
        else if(answer == 2)
        {
            answerValue = false;
            validAnswer = true;
        }
        else
        {
            std::cout<<"Wrong input. Please pick a valid option" << std::endl;
        }
    }
    //music1.stop();
    return answerValue;
}

Player* setupPlayer()
{
    std::string playerName, heroType;
    bool validHero = false;
    int heroTypeValue;
    std::cout<<"What is you name?"<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, playerName);
    while(validHero==false)
    {
        std::cout<<"What do you want to be?" << std::endl 
                    << "1. Wizard" << std::endl 
                    << "2. Warrior" << std::endl
                    << "3. Rogue" << std::endl;
        std::cin>>heroTypeValue;
        
        switch (heroTypeValue)
        {
            case 1: 
            {
                heroType = "Wizard";
                validHero = true;
                break;
            }
            case 2: 
            {
                heroType = "Warrior";
                validHero = true;
                break;
            }
            case 3:  
            {
                validHero = true;
                heroType = "Rogue";
                break;
            }
            default:
                system("cls");
                std::cout<<"Wrong input. Please pick a valid option" << std::endl;
                break;
        }
    }
    system("cls");
    std::cout<<"Welcome " << heroType << " " << playerName << std::endl; 
    std::cout << "Press any key to continue..." << std::endl;
    _getch();
    system("cls");
    if(heroType == "Wizard")
    {
        Player* player = new Wizard(playerName);
        return player;
    }
    else if(heroType == "Warrior")
    {
        Player* player = new Warrior(playerName);
        return player;
    }
    else 
    {
        Player* player = new Rogue(playerName);
        return player;
    }
    
}

std::string roadChosen;

void roadsScene()
{
    int roadChosenValue;

    std::cout<<"You arrived at a crossroads. Where do you want to go?" << std::endl 
                << "1. To the village" << std::endl 
                << "2. To the forest" << std::endl
                << "3. To the caves" << std::endl;
    std::cin>>roadChosenValue;
    switch (roadChosenValue)
    {
        case 1: 
        {
            roadChosen = "village";
            break;
        }
        case 2: 
        {
            roadChosen = "forest";
            break;
        }
        case 3:  
        {
            roadChosen = "caves";
            break;
        }
        default:
            roadChosen = "Wrong Input";
            break;
    }
    system("cls");
    if(!(roadChosen == "village" || roadChosen == "forest" || roadChosen == "caves"))
    {
        std::cout<<"Wrong input. Please pick a valid option." << std::endl;
        roadsScene();
    }
}


bool chestScene()
{
    int chestAnswerValue;
    bool validAnswer = false, openChest;
    std::cout << "You are heading to the " << roadChosen << ". \n";
    while(validAnswer==false)
    { 
        std::cout << "On the road, you find a chest. Do you open it?" << std::endl
                    << "1. Yes" << std::endl 
                    << "2. No" << std::endl;
        std::cin>>chestAnswerValue;
        switch (chestAnswerValue)
        {
            case 1: 
            {
                validAnswer=true;
                openChest = true;
                break;
            }
            case 2: 
            {
                validAnswer=true;
                openChest = false;
                break;
            }
        }
        system("cls");
        if(validAnswer==false)
        {
            std::cout<<"Wrong input. Please pick a valid option." << std::endl;
        }
    }
    return openChest;
}

Enemy* generateRandomEnemy()
{
    EnemyType randomEnemyType = (EnemyType) (rand() % 3);
    if(randomEnemyType == EnemyType::Orc)
    {
        Enemy* enemy = new Orc();
        std::cout << "Orc enemy generated \n";
        return enemy;
    }
    else if (randomEnemyType == EnemyType::Goblin)
    {
        Enemy* enemy = new Goblin();
        std::cout << "Goblin enemy generated \n";
        return enemy;
    }
    else 
    {
        Enemy* enemy = new Troll();
        std::cout << "Troll enemy generated \n";
        return enemy;
    }
}

std::string generateFirstAttacker()
{
    enum Oponents{Player, Enemy};
    Oponents randomfirstAttacker = (Oponents) (rand() % 2);
    if(randomfirstAttacker == Oponents::Player)
    {
        return "Player";
    }
    else if (randomfirstAttacker == Oponents::Enemy)
    {
        return "Enemy";
    }
}

bool battleScene(Player* player, Enemy* enemy)
{
    if(generateFirstAttacker() == "Player")
    {
        std::cout << "Player attacks first \n";
        do 
        {
            enemy->setHP( enemy->getHP() - player->Attack() );
            if (enemy->getHP() <= 0)
            {
                return true;
            }

            player->setHealth( player->getHealth() - (enemy->getDamage() - player->getItemsDefencePower()) );
            if(player->getHealth() <= 0)
            {
                return false;
            }
        }
        while ( (player->getHealth() > 0) && (enemy->getHP() > 0) );
    }
    else
    {
        std::cout << "Enemy attacks first \n";
        do 
        {
            player->setHealth( player->getHealth() - (enemy->getDamage() - player->getItemsDefencePower()) );
            if(player->getHealth() <= 0)
            {
                return false;
            }

            enemy->setHP( enemy->getHP() - player->Attack() );
            if (enemy->getHP() <= 0)
            {
                return true;
            }
        }
        while ( (player->getHealth() > 0) && (enemy->getHP() > 0) );
    }
}
