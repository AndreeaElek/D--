#include "Misc.h"

int main(int argc, char const *argv[])
{
    bool restart = true;
    system("cls");
    
    sf::Music music1, music2, music3;
    music1.openFromFile("Main_Menu.wav");
    music2.openFromFile("Exploring.wav");
    music3.openFromFile("Final_Battle.wav");
    music1.setVolume(30);
    music2.setVolume(30);
    music3.setVolume(30);
    music1.play();
   while(restart==true)
   {
        if(introScene()) 
        {
            Player* player = setupPlayer();
            music1.pause();
            music2.play();
            roadsScene();
            if(chestScene())
            {
                player->CreateChestItem();
            }
            player->CheckInventory();

            music2.stop();
            music3.play();
            std::cout << "Your healt before the battle: " << player->getHealth() << std::endl;
            Enemy* enemy = generateRandomEnemy();
            if(battleScene(player, enemy) == true)
            {
                std::cout<<"You won! \n";
                std::cout<<"Your current health is: " << player->getHealth() << std::endl;
                delete enemy;
                std::cout << "Press any key to continue..." << std::endl;
                _getch();
                std::cout << "Continuint game... \n";
            }
            else
            {
                std::cout<<"You lost! \n";
                std::cout << "Press any key to continue..." << std::endl;
                _getch();
                delete enemy;
            }

            player->DeleteItems();
            delete player;
            music3.stop();
            music1.play();
        }
        else
        {
            std::cout << "You chose not to play" << std::endl; 
        }
        std::cout<< "Game Over" << std::endl;
        restart=restartGame();
        system("cls");
    }

    music1.stop();

    return 0; 
} 
