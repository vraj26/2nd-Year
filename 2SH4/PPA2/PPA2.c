#include <stdio.h>
#include "MacUILib.h"

// PPA2 GOAL: 
//       Construct the game backbone where the player can control an object 
//       to move freely in the game board area with border wraparound behaviour.

// Watch Briefing Video and Read Lab Manual before starting on the activity!



// PREPROCESSOR CONSTANTS DEFINITION HERE
/////////////////////////////////////////



// GLOBAL VARIABLE DEFINITION HERE
/////////////////////////////////////////

int exitFlag; // Program Exiting Flag - old stuff

// For storing the user input - from PPA1
char input;
int motion;

// [TODO] : Define objPos structure here as described in the lab document
struct objPos
{
    int x;		// x-coordinate of an object
    int y;		// y-coordinate of an object
    int speed;  //speed of player
    int lvl;    // level of the speed 
    char symbol;	// The ASCII symbol of the object to be drawn on the screen
} player;
// struct objPos player;

enum {
    NORMAL,
    LEFT,
    RIGHT,
    UP,
    DOWN
} FSM;

// [TODO] : Define the Direction enumeration here as described in the lab document
//          This will be the key ingredient to construct a simple Finite State Machine
//          For our console game backbone.



// FUNCTION PROTOTYPING DEFINITION HERE
/////////////////////////////////////////

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

// You may insert additional helper function prototypes below.
// 
// As a good practice, always insert prototype before main() and implementation after main()
// For ease of code management.



// MAIN PROGRAM LOOP
/////////////////////////////////////////
// This part should be intuitive by now.
// DO NOT TOUCH

int main(void)
{

    Initialize();

    while(!exitFlag)  
    {
        GetInput();

        RunLogic();

        DrawScreen();

        LoopDelay();
    }

    CleanUp();

}


// INITIALIZATION ROUTINE
/////////////////////////////////////////
void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    input = 0; // NULL
    exitFlag = 0;  // not exiting    
   
    // [TODO] : Initialize more variables here as seen needed.
    //          PARTICULARLY for the structs!!

    player.x = 5;
    player.y = 5;
    player.symbol = 'V';
    player.speed = 100000;
    player.lvl = 3;



}


// INPUT PROCESSING ROUTINE
/////////////////////////////////////////
void GetInput(void)
{
    // [TODO] : Implement Asynchronous Input - non blocking character read-in    
    //          (Same as PPA1)
    if(MacUILib_hasChar()) {
        input = MacUILib_getChar();
    } else{
        input = 0;
    }



}


// PROGRAM LOGIC ROUTINE
/////////////////////////////////////////
void RunLogic(void)
{
    // [TODO] : First, process the input by mapping
    //          WASD to the corresponding change in player object movement direction
    //if escape is pressed then stop 
    /*if(input == 27){
        FSM = STOP;
    } else if (input == 119 || input == 87){ // if 'w' or 'W' is pressed then assign a case 
        FSM = UP;
    } else if  (input == 97 || input == 65){ //same case but for 'a' or 'A'
        FSM = LEFT;
    } else if(input == 115 || input == 83) { //same case but for 's' or 'S'
        FSM = DOWN;
    } else if (input == 100 || input == 68) { //same case but for 'd' or 'D'
        FSM = RIGHT;
    }*/

    if(input != 0)  // if not null character
    {
        switch(input)
        {   
            case 119: // for w
                if(FSM == NORMAL || FSM == LEFT || FSM == RIGHT){
                    FSM = UP;
                }
                break;
            case 97: //for a
                if(FSM == NORMAL || FSM == UP || FSM == DOWN){
                    FSM = LEFT;
                }
                break;
            case 115: //for s
                if(FSM == NORMAL || FSM == LEFT || FSM == RIGHT){
                    FSM = DOWN;
                }
                break; 
            case 100: //for d
                if(FSM == NORMAL || FSM == UP || FSM == DOWN){
                    FSM = RIGHT;
                }
                break;                  
            case 27:  // exit
                exitFlag = 1;
                break;

            //above and beyond
            case 49:
                player.speed = 25000;
                player.lvl = 1;
                break;
            case 50:
                player.speed = 50000;
                player.lvl = 2;
                break;
            case 51:
                player.speed = 100000;
                player.lvl = 3;
                break;
            case 52:
                player.speed = 200000;
                player.lvl = 4;
                break;
            case 53: 
                player.speed = 300000;
                player.lvl = 5;


            // Add more key processing here
            // Add more key processing here
            // Add more key processing here    


            default:
                break;
        }
        input = 0;
    }



    // [TODO] : Next, you need to update the player location by 1 unit 
    //          in the direction stored in the program
    if(FSM == UP){
        player.y--;
        //if player is too exceeds the border, then reset back at bottom of border
        if(player.y < 1){
            player.y = 8;
        }
    } else if (FSM == LEFT){
        player.x--;
        //if the player is too much to the left then reset the position all the way to the right before border
        if(player.x < 1){
            player.x = 18;
        }
    } else if (FSM == DOWN){
        player.y++;
        //if the player exceeds the border at the bottom, then reset him back to the top
        if(player.y > 8){
            player.y = 1;
        }

    } else if (FSM == RIGHT){
        player.x++;
        //if the player exceeds the border at the right, then reset back to the left
        if(player.x > 18){
            player.x = 1;
        }
    }
    /*
    //for W
    if(motion == 1 || motion == 3){
                    player.y--;
                }
                motion = 0; //0 is for up
    
    //for a
    if(motion == 0 || motion == 2){
                    player.x--;
                }
                motion = 1; //1 is for left
    //for s
    if(motion == 1 || motion == 3){
                    player.y++;
                }
                motion = 2; //2 is for down
    //for d
    if(motion == 0 || motion == 2){
                    player.x++;
                }
                motion = 3; //1 is for right*/


    // [TODO] : Heed the border wraparound!!!

    

}



// SCREEN DRAWING ROUTINE
/////////////////////////////////////////
void DrawScreen(void)
{
    // [TODO] : Implement the latest drawing logic as described in the lab manual
    //
    //  1. clear the current screen contents
    MacUILib_clearScreen();
    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 20; x++){
            if(x == 0 || x == 19 || y == 0 || y == 9){
                MacUILib_printf("#");
            } else if (x == player.x && y == player.y) {
                MacUILib_printf("%c",player.symbol);
            }
            else{
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Use WASD to move\n");
    MacUILib_printf("Use \"1\" \"2\" \"3\" \"4\" \"5\" to change your speed level\n Lower Levels mean faster gameplay, Higher Levels mean slower gameplay\n");
    MacUILib_printf("Current Speed Level: %d\n", player.lvl);
    MacUILib_printf("Player Co-ords (x,y): (%d,%d)\n", player.x, player.y);
    
    //MacUILib_printf("Key Pressed: %c", input);
    //  2. Iterate through each character location on the game board
    //     using the nested for-loop row-scanning setup.

    //  3. For every visited character location on the game board
    //          If on border on the game board, print a special character
    //          If at the player object position, print the player symbol
    //          Otherwise, print the space character
    //     Think about how you can format the screen contents to achieve the
    //     same layout as presented in the lab manual

    //  4. Print any debugging messages as seen needed below the game board.
    //     As discussed in class, leave these debugging messages in the program
    //     throughout your dev process, and only remove them when you are ready to release
    //     your code. 

   


}



// PROGRAM LOOOP DELAYER ROUTINE
/////////////////////////////////////////
void LoopDelay(void)
{
    // Change the delaying constant to vary the movement speed.
    MacUILib_Delay(player.speed);    
}



// PROGRAM CLEANUP ROUTINE
/////////////////////////////////////////
// Recall from PPA1 - this is run only once at the end of the program
// for garbage collection and exit messages.
void CleanUp(void)
{
    MacUILib_uninit();
}



