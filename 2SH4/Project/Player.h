#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h" //including FOOD class

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food *foodReference);
        ~Player();

        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir();
        


        void movePlayer();
        //need more actions in here
        //after inserteing head but ebfore remobing tail, do the following
        //check if new head position collides w food
        // if yes increment scoree in GM, genereate new good
        //dfo not remove tail
        // otehrwise, remobve tail and move on

        bool checkFoodConsumption();
        void increasePlayerLength();
        //bool checkSelfCollision();


        //add self collision check
        //if self collided, set losefalg and exitFalg = true through GM
        //this will break the program loop and end game

        //if ending, need to diffrentiate end game state
        //LOST = Lost messafe
        //otherwise display won game status 

    private:
        objPosArrayList* playerPosList;   // Upgrade this in iteration 3.       
        enum Dir myDir;
        

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;

        //need reference to Food class
        Food* food;
};

#endif