#include "GameMechs.h"
#include "MacUILib.h"
#include "Player.h"

GameMechs::GameMechs()
{
    input = '\0';
    boardSizeX = 30;
    boardSizeY = 15;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    foodPos.setObjPos(1, 1, 'o'); //deafult pos
    

}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = '\0';
    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    foodPos.setObjPos(-1, -1, 'o');
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    //delete[] GameMechs; //what to do??
}

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    if(MacUILib_hasChar()) {
        input = MacUILib_getChar();
    } else if(input == 27){ // escape as exit
        setExitTrue();
    } 
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}
