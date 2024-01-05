#include "Player.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include "Food.h"
#include "objPos.h"

Player::Player(GameMechs* thisGMRef, Food* foodReference)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    //pass on reference
    food = foodReference;

    //setting position of array list in the middle of the hboard
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,
                        mainGameMechsRef->getBoardSizeY()/2,
                        '*');
    // more actions to be included

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);


    

}


Player::~Player()
{
    // delete any heap members here
    //empty for now
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    //returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list (dont worrty about this for now)
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  

    //get input and switch it depending on case
    char input = mainGameMechsRef->getInput();
    switch(input){
        case 'w': // for w

            //if input is only going left or right or is not moving, then switch to up
            if(myDir == STOP || myDir == LEFT || myDir == RIGHT){
                myDir = UP;
                
            }
            break;

        //same logic applies here, if going up, down or stop only then switch to left
        case 'a': //for a
            if(myDir == STOP || myDir == UP || myDir == DOWN){
                myDir = LEFT;
                
            }
            break;
        case 's': //for s
            if(myDir == STOP || myDir == LEFT || myDir == RIGHT){
                myDir = DOWN;
            }
            break; 
        case 'd': //for d
            if(myDir == STOP || myDir == UP || myDir == DOWN){
                myDir = RIGHT;
            }
            break;   
        default:
            break;      
    }     
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    objPos currHead;
    playerPosList->getHeadElement(currHead); // holding pos information of the curent head
    //board size from gamemechanism
    int boardX = mainGameMechsRef->getBoardSizeX();
    int boardY = mainGameMechsRef->getBoardSizeY();

    objPos tempPos; //this tempPos will be needed to get position of the snake elements
    bool samePos = false; //same position flag for suicide
    

    

    if(myDir == UP){
        currHead.y--;
        //if playerPos is too exceeds the border, then reset back at bottom of border
        if(currHead.y < 1){
            currHead.y = boardY-2;
        }
    } else if (myDir == LEFT){
        currHead.x--;
        //if the playerPos is too much to the left then reset the position all the way to the right before border
        if(currHead.x < 1){
            currHead.x = boardX-2;
        }
    } else if (myDir == DOWN){
        currHead.y++;
        //if the playerPos exceeds the border at the bottom, then reset him back to the top
        if(currHead.y > boardY-2){
            currHead.y = 1;
        }

    } else if (myDir == RIGHT){
        currHead.x++;
        //if the playerPos exceeds the border at the right, then reset back to the left
        if(currHead.x > boardX-2){
            currHead.x = 1;
        }
    }

    //new currenth ead should be inserted ot the head of the list
    

    if(checkFoodConsumption()){
        //calls on another function
        increasePlayerLength();
    } else {
        //if there is no food consumption then move normally
        playerPosList->insertHead(currHead);
        playerPosList->removeTail();
    }

    //self suicide
    //iterate through playerPosList (except for head) and end game when head is equyal to any other position
    for(int i =1; i < playerPosList->getSize(); i++){
        playerPosList->getElement(tempPos, i);
        samePos = tempPos.isPosEqual(&currHead);

        if(samePos){
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
            break;
        }
    }
    

    
}


bool Player::checkFoodConsumption(){

    //grab temporary food position
    objPos tempFoodPos;
    food->getFoodPos(tempFoodPos);

    //grab current head of snake
    objPos currHead;
    playerPosList->getHeadElement(currHead);
    
    //if food collides with head then increment score and generate another food
    if(tempFoodPos.isPosEqual(&currHead)){
    
        mainGameMechsRef->incrementScore();

        
        food->generateFood(playerPosList);

        return true;

    }
    return false;
}




void Player::increasePlayerLength(){
    //simply add a head
    objPos currHead;
    playerPosList->getHeadElement(currHead);
    playerPosList->insertHead(currHead);
}



