#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"
#include "objPosArrayList.h"


using namespace std;



#define DELAY_CONST 100000


//OOD benefit, very limited globa variable declaration
//In Advanced OOD, there won't be any global variables
GameMechs* myGM;
Player*  myPlayer; // aLL are references
Food* food;

//bool exitFlag; //ask to comment or not

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    

    myGM = new GameMechs(30,15); // makes the board size 30x15
    food = new Food();
    myPlayer = new Player(myGM, food);
    

    
    objPosArrayList *tempSnake = myPlayer->getPlayerPos();
    food->generateFood(tempSnake);

    
    
}

void GetInput(void)
{
   myGM->getInput(); 
}


void RunLogic(void)
{
  
    myPlayer-> updatePlayerDir();
    myPlayer->movePlayer();
   
    myGM->clearInput(); //dont repeadtedly process same input
    
}

void DrawScreen(void)
{
   MacUILib_clearScreen(); 
    
    
    //for playerPosition
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;
    bool drawn;

    //user to get coordinates of tempFood
    objPos tempPosFood;
    food->getFoodPos(tempPosFood);
    

        for (int i = 0; i < myGM->getBoardSizeY(); i++)
        {
            for (int j = 0; j < myGM->getBoardSizeX(); j++)
            {
                
                drawn = false;
                //iterate thorugh palyerbody and check if the copy matches i and j
                for(int k =0; k < playerBody->getSize(); k++){

                    playerBody->getElement(tempBody, k);

                    //if the body is equal to the j and i element then you print the symbol
                    if(tempBody.x == j && tempBody.y == i){
                        MacUILib_printf("%c", tempBody.symbol);
                        drawn = true;
                        break;
                    }

                }
                //if drawn then dont print anything else
                if(drawn) continue;
                
                


                if (i == 0 || i == myGM->getBoardSizeY() -1 || j == 0 || j == myGM->getBoardSizeX()-1)
                {
                    
                    MacUILib_printf("%c", '#');
                }

                
                // Print food symbol randomly
                else if (i == tempPosFood.y && j == tempPosFood.x)
                {

                    MacUILib_printf("%c", tempPosFood.symbol);
                }

               
                else 
                {
                    MacUILib_printf("%c", ' ');
                }

                //MacUILib_printf("i: %d j:%d\n", i, j);
                
                
            }

            MacUILib_printf("\n");

            
        }
        


        
        //MacUILib_printf("Input: %c\n", myGM->getInput());
        MacUILib_printf("BoardSize: %dx%d\n", 
                        myGM->getBoardSizeX(), 
                        myGM->getBoardSizeY() 
                        );
        MacUILib_printf("Score: %d\n", myGM->getScore());
        MacUILib_printf("Press escape keyword to end game\n");

        
        

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    if (myGM->getLoseFlagStatus() == true)
                {
                    MacUILib_printf("\nSnake has suicided, Game Over!");
                    MacUILib_printf("\nYour final score was: %d", myGM->getScore());
                }
    
    MacUILib_clearScreen();    
   

    if (myGM->getLoseFlagStatus() == true)
        {
            MacUILib_printf("\nSnake has suicided, Game Over!");
            MacUILib_printf("\nYour final score was: %d", myGM->getScore());
        }

    else 
        {
            MacUILib_printf("\nGame has been exited!");
            MacUILib_printf("\nYour final score was: %d", myGM->getScore());
        }


    
    MacUILib_uninit();

    

    //remove heap instances
    delete[] myGM;
    delete[] myPlayer;
    delete [] food;

    

    
}

