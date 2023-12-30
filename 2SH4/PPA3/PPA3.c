#include <stdio.h>
#include "MacUILib.h"
#include "myStringLib.h"   // This is your first custom C library

// [TODO] Import the required library for rand() and srand()
// [TODO] Import the required library for accessing the current time - for seeding random number generation
#include <time.h>




// PREPROCESSOR DIRECTIVE CONSTANTS
// ================================
// For program-wide constants, define them here using #define.  Add as seen needed.

// [COPY AND PASTE FROM PPA2] Copy your additional preprocessor constants from PPA2 and paste them below


// [TODO] Then, define more constants here as seen needed.





// GLOBAL VARIABLES
// ================================

int exitFlag; // Program Exiting Flag

// [COPY AND PASTE FROM PPA2] Copy your additional global from PPA2 and paste them below
char input;
int moveCount;
int isMoving;

// [TODO] : Define objPos structure here as described in the lab document
struct objPos
{
    int x;		// x-coordinate of an object
    int y;		// y-coordinate of an object
    char symbol;	// The ASCII symbol of the object to be drawn on the screen
} player;
// the pointer to objPos
struct objPos* itemBin;




enum {
    NORMAL,
    LEFT,
    RIGHT,
    UP,
    DOWN
} FSM; //remember to initialize to zero

const char strGoal[] = "McMaster-ECEVraj";
char* ptrMystery = NULL;


// [TODO] Declare More Global Variables as seen needed.

// [TODO] Declare Global Pointers as seen needed / instructed in the manual.








// FUNCTION PROTOTYPES
// ================================
// Declare function prototypes here, so that we can organize the function implementation after the main function for code readability.

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

// [TODO] In PPA3, you will need to implement this function to generate random items on the game board
//        to set the stage for the Scavenger Hunter game.
// list[]       The pointer to the Item Bin
// listSize     The size of the Item Bin (5 by default)
// playerPos    The pointer to the Player Object, read only.
// xRange       The maximum range for x-coordinate generation (probably the x-dimension of the gameboard?)
// yRange       The maximum range for y-coordinate generation (probably the y-dimension of the gameboard?)
// str          The pointer to the start of the Goal String (to choose the random characters from)
void GenerateItems(struct objPos list[], const int listSize, const struct objPos *playerPos, const int xRange, const int yRange, const char* str);




// MAIN PROGRAM
// ===============================
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
// ===============================
void Initialize(void)
{
    MacUILib_init();

    MacUILib_clearScreen();

    // [COPY AND PASTE FROM PPA2] Copy your initialization routine from PPA2 and paste them below
    input = 0; // NULL
    exitFlag = 0;  // not exiting    
    moveCount = 0;
    isMoving = 0;
    
    itemBin = (struct objPos*)malloc(5* sizeof(struct objPos));

    //MAYBE TRY FOR LOOP HERE
    // if(itemBin != '\0'){
    //     for(int i =0; i <5; i++){
    //         itemBin[i].symbol = 'A' + i;
    //         itemBin[i].x = (1 + i);
    //         itemBin[i].y = (1 + i);
    //     }
    // }
    GenerateItems(itemBin, 5, &player, 19, 9, strGoal);
    
   
    ptrMystery = (char*)malloc(17);

    if(ptrMystery != '\0'){
        for(int i = 0; i < my_strlen(strGoal); i++){
            ptrMystery[i] = '?';
        }
        ptrMystery[my_strlen(strGoal)] = '\0';
    }

    // [TODO] : Initialize more variables here as seen needed.
    //          PARTICULARLY for the structs!!

    player.x = 6;
    player.y = 6;
    player.symbol = '@';
    
    // [TODO] Initialize any global variables as required.
    exitFlag = 0;  // 0 - do not exit, non-zero - exit the program

    
    // [TODO] Allocated heap memory for on-demand variables as required.  Initialize them as required.

    // [TODO] Seed the random integer generation function with current time.

    // [TODO] Generate the initial random items on the game board at the start of the game.

    
}




// INPUT COLLECTION ROUTINE
// ===============================
void GetInput(void)
{

    // Asynchronous Input - non blocking character read-in
    
    // [COPY AND PASTE FROM PPA2] Copy your input collection routine from PPA2 and paste them below
    if(MacUILib_hasChar()) {
        input = MacUILib_getChar();
    } else {
        input = 0;
    }

    // [TODO] Though optional for PPA3, you may insert any additional logic for input processing.

   
}




// MAIN LOGIC ROUTINE
// ===============================
void RunLogic(void)
{
    // [COPY AND PASTE FROM PPA2] Copy your main logic routine from PPA2 and paste them below
if(input != 0)  // if not null character
    {
        switch(input)
        {   
            case 119: // for w
                if(FSM == NORMAL || FSM == LEFT || FSM == RIGHT){
                    FSM = UP;
                    isMoving = 1;
                }
                break;
            case 97: //for a
                if(FSM == NORMAL || FSM == UP || FSM == DOWN){
                    FSM = LEFT;
                    isMoving = 1;
                }
                break;
            case 115: //for s
                if(FSM == NORMAL || FSM == LEFT || FSM == RIGHT){
                    FSM = DOWN;  
                    isMoving = 1; 
                }
                break; 
            case 100: //for d
                if(FSM == NORMAL || FSM == UP || FSM == DOWN){
                    FSM = RIGHT;
                    isMoving = 1;
                }
                break;                  
            case 27:  // exit
                exitFlag = 1;
                break;


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
    // [TODO]   Implement the Object Collision logic here
    //
    //      Simple Collision Algorithm
    //      1. Go through all items on board and check their (x,y) against the player object x and y.
    //      2. If a match is found, use the ASCII symbol of the collided character, and 
    //         find all the occurrences of this ASCII symbol in the Goal String
    //      3. For every occurrence, reveal its ASCII character at the corresponding location in the
    //         Collected String
    //      4. Then, determine whether the game winning condition is met.

    char symbolCollided;
    int charCollect;

    for(int i =0;i<5;i++){
        if(itemBin[i].x == player.x && itemBin[i].y == player.y){
            symbolCollided = itemBin[i].symbol;

            charCollect = 0;
            for(int j= 0; j < my_strlen(strGoal); j++){
                if (ptrMystery[j] == symbolCollided){
                    charCollect = 1;
                }
                
                break;
            }

            if(!charCollect){
                for(int j =0; j < my_strlen(strGoal); j++){
                    if(strGoal[j] == symbolCollided){
                        ptrMystery[j] = symbolCollided;
                    }
                }
            }

            if(my_strcmp(strGoal, ptrMystery)){
                exitFlag = 1;
            }
            GenerateItems(itemBin, 5, &player, 19, 9, strGoal);
            break;
        }
        
    }
    



    // [TODO]   Implement Game Winning Check logic here
    //
    //      Game Winning Check Algorithm
    //      1. Check if the contents of the Collected String exactly matches that of the Goal String.
    //         YOU MUST USE YOUR OWN my_strcmp() function from Lab 3.
    //      2. If matched, end the game.
    //      3. Otherwise, discard the current items on the game board, and 
    //         generate a new set of random items on the board.  Game continues.
    
}



// DRAW ROUTINE
// ===============================
void DrawScreen(void)
{
   
    // [COPY AND PASTE FROM PPA2] Copy your draw logic routine from PPA2 and paste them below
    int flag;
    MacUILib_clearScreen();
    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 20; x++){
            flag = 0;
            for(int i = 0; i < 5; i++){
                if(x == itemBin[i].x & y == itemBin[i].y){
                    MacUILib_printf("%c", itemBin[i].symbol);
                    flag = 1;
                }
            }
            if(x == 0 || x == 19 || y == 0 || y == 9){
                MacUILib_printf("#");
            } else if (x == player.x && y == player.y) {
                MacUILib_printf("%c",player.symbol);
                if(isMoving){
                    moveCount++;
                }
            } 
            else if (!flag){
                MacUILib_printf(" ");
            }
            
        }
        MacUILib_printf("\n");
    }


    MacUILib_printf("Use WASD to move\n");
    MacUILib_printf("Player Co-ords (x,y): (%d,%d)\n", player.x, player.y);
    MacUILib_printf("Mystery String: ");
    for(int i =0; i < my_strlen(strGoal); i++){
        MacUILib_printf("%c", ptrMystery[i]);
    }
    
    MacUILib_printf("\nMove Count: %d", moveCount);
    
    
    



    // [TODO]   Insert somewhere in the draw routine to draw the randomly generated items on the board.

    // [TODO]   Display the "Mystery String" contents at the bottom of the game board
    //          To help players keep track of their game progress.
    
    
    
}





// DELAY ROUTINE
// ===============================make

void LoopDelay(void)
{
    MacUILib_Delay(100000); // 0.1s delay
}





// TEAR-DOWN ROUTINE
// ===============================
void CleanUp(void)
{
    // [TODO]   To prevent memory leak, free() any allocated heap memory here
    //          Based on the PPA3 requirements, you need to at least deallocate one heap variable here.
    free(ptrMystery);
    free(itemBin);


    // Insert any additional end-game actions here.
    

    MacUILib_uninit();
}




// The Item Generation Routine
////////////////////////////////////
void GenerateItems(struct objPos list[], const int listSize, const struct objPos *playerPos, const int xRange, const int yRange, const char* str)
{
    // This is possibly one of the most conceptually challenging function in all PPAs
    // Once you've mastered this one, you are ready to take on the 2SH4 course project!

    // Random Non-Repeating Item Generation Algorithm
    ////////////////////////////////////////////////////
    
    srand(time(NULL));
    int xCand; 
    int yCand;
    int index;
    char candSymbol;
    int symFound;
    

    //ABOVE AND BEYOND STARTS HERE//
    
   for(int i =0; i < listSize; i++){

        do{
            xCand = 1 + rand() % (xRange - 1);//the following ranges start from 1 and end to xRange -1 and similarly to yRange
            yCand = 1 + rand() % (yRange - 1);

        } while(xCand == player.x || yCand == player.y);
        

        

        //assume sym is found for while loop to function
        if(i <2){
        symFound = 1;
        while(symFound){
            candSymbol = strGoal[rand() % my_strlen(strGoal)];
            symFound = 0;

            for(int j= 0; j < i; j++){
                if(list[j].symbol == candSymbol){
                    symFound = 1;
                    break;
                }
            }
        }
        }
        else{
            for(int r =0; r < my_strlen(strGoal); r++){
                do{
                    candSymbol = rand() %(64-48)+48;
                } while(candSymbol == player.symbol || candSymbol == '#' || candSymbol == ' ' || candSymbol == strGoal[r]);
            }
            // do{
            //     candSymbol = 33 + rand() % (126-33+1);
            // } while(candSymbol == player.symbol || candSymbol == '#' || candSymbol == ' ' || candSymbol == strGoal[i]);
        }
        

        list[i].symbol = candSymbol;
        list[i].x = xCand;
        list[i].y = yCand;
        
   }
    // Use random number generator function, rand(), to generate a random x-y coordinate and a random choice of character from the Goal String as the ASCII character symbol.
    //      The x and y coordinate range should falawl within the xRange and yRange limits, which should be the x- and y-dimension of the board size.
    // This will then be a candidate of the randomly generated Item to be placed on the game board.

    // In order to make sure this candidate is validated, it needs to meet both criteria below:
    //  1. Its coordinate and symbol has not been previously generated (no repeating item)
    //  2. Its coordinate does not overlap the Player's position
    // Thus, for every generated item candidate, check whether its x-y coordinate and symbol has previously generated.  
    //  Also, check if it overlaps the player position
    //      If yes, discard this candidate and regenerate a new one
    //      If no, this candidate is validated.  Add it to the input list[]

    // There are many efficient ways to do this question
    //  We will take a deep dive into some methods in 2SI.

}
