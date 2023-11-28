#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;
Food* food;

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

    // heap -- deallocate
    
    myGM = new GameMechs(20,10); // make the board size 20x10
    food = new Food(myGM); // initialze food
    myPlayer = new Player(myGM,food);

    // food generation

    objPosArrayList* playerPosList = myPlayer->getPlayerPos(); // upgraded in iteration 3
    food->generateFood(playerPosList); 

}

void GetInput(void)
{
   myGM->getInput();
}

void RunLogic(void)
{
    objPosArrayList* playerPosList = myPlayer->getPlayerPos(); // to make within scope of increment score
                                                               // is this the right way?
    myGM->incrementScore(playerPosList);

    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGM->clearInput(); // so the input isn't repetedly processed

    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    
    bool drawn;

    objPosArrayList* playerBody = myPlayer->getPlayerPos(); //refernce to player position
    objPos tempBody;

    objPos tempFood;
    food->getFoodPos(tempFood); // get the food pos

    for(int i = 0; i < myGM->getBoardSizeY(); i++){ // rows
    
        for(int j = 0; j < myGM->getBoardSizeX(); j++){ // columns
            
            drawn = false;

            for (int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody, k);
                
                if (tempBody.x == j && tempBody.y == i)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if (drawn) continue;
            // if player was drawn, don't draw anything below.

            if(j == 0 || j == myGM->getBoardSizeX()-1 || i == 0 || i == myGM->getBoardSizeY()-1){
                MacUILib_printf("%s","#");
            }

            else if(i == tempFood.y && j == tempFood.x){
                MacUILib_printf("%c", tempFood.symbol);
            }

            else{
                MacUILib_printf("%s"," ");
            }
        }

        MacUILib_printf("%s","\n");
    }

    MacUILib_printf("Player positions:\n");
    for(int m = 0; m < playerBody->getSize(); m++)
    {
        playerBody->getElement(tempBody, m);
        MacUILib_printf("<%d, %d>\n", tempBody.x, tempBody.y);
    }


    MacUILib_printf("Score: %d\n", myGM->getScore());
    MacUILib_printf("Food Pos: <%d, %d>, + %c\n", tempFood.x, tempFood.y, tempFood.symbol);

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
    // deallocating heap members

    delete myGM;
    delete myPlayer;
    delete food;
}
