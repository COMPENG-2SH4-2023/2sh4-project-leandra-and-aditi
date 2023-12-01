#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 150000

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
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    objPosArrayList* playerPosList = myPlayer->getPlayerPos(); // to make within scope of increment score
                                                               // is this the right way?

    myGM->incrementScore(playerPosList); // would not work unless put in run logic which makes sense

    //myPlayer->CheckSelfCollision();

    myGM->clearInput(); // so the input isn't repetedly processed

    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    
    bool drawn;

    objPosArrayList* playerBody = myPlayer->getPlayerPos(); //refernce to player position
    objPos tempBody;

    objPos tempFood;
    food->getFoodPos(tempFood); // reference to the food pos

    for(int i = 0; i < myGM->getBoardSizeY(); i++) // rows
    {
    
        for(int j = 0; j < myGM->getBoardSizeX(); j++) // columns
        { 
            
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

            if(j == 0 || j == myGM->getBoardSizeX()-1 || i == 0 || i == myGM->getBoardSizeY()-1)
            {
                MacUILib_printf("%s","#");
            }

            else if(i == tempFood.y && j == tempFood.x)
            {
                MacUILib_printf("%c", tempFood.symbol);
            }

            else
            {
                MacUILib_printf("%s"," ");
            }
        }

        MacUILib_printf("%s","\n");
    }

    // display messages

    MacUILib_printf("Score: %d\n", myGM->getScore());

        // when self collision occurs

    if(myGM->getLoseFlagStatus() == true && myGM->getExitFlagStatus() == true)
    {
        MacUILib_printf("\nOh no! you bit yourself and are in pain :(\n");
    }

        // force end game

    if(myGM->getLoseFlagStatus() != true && myGM->getExitFlagStatus() == true)
    {
        MacUILib_printf("\nGame ended.\n");
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    //MacUILib_clearScreen();    -- interfering with displaying ending messages so I took out
  
    MacUILib_uninit();
    // deallocating heap members

    delete myGM;        // do we need destructors or does this do it?
    delete myPlayer;
    delete food;
}
