#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"


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
    myPlayer = new Player(myGM);

    // heap -- deallocate

    myGM = new GameMechs(20,10); // make the board size 20x10
    myPlayer = new Player(myGM);

    food = new Food(myGM); // initialze food

    // food generation

    objPos playPos;
    myPlayer->getPlayerPos(playPos);
    food->generateFood(playPos); // input in the generate function is player pos
                                 // since it is checking coordinates do not match player pos

}

void GetInput(void)
{
   myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    food->updateFood();

    myGM->clearInput(); // so the input isnt repetedly processed

    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    int i;
    int j;

    objPos tempPos;
    myPlayer->getPlayerPos(tempPos); // get the player pos

    objPos tempFood;
    food->getFoodPos(tempFood); // get the food pos

    for(i = 0; i < myGM->getBoardSizeY(); i++){ // rows
    
        for(j = 0; j < myGM->getBoardSizeX(); j++){ // columns

            if(j == 0 || j == myGM->getBoardSizeX()-1 || i == 0 || i == myGM->getBoardSizeY()-1){
                MacUILib_printf("%s","#");
            }

            else if(i == tempPos.y && j == tempPos.x){
                MacUILib_printf("%c", tempPos.symbol);
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

    MacUILib_printf("Player Pos: <%d, %d>, + %c\n", tempPos.x, tempPos.y, tempPos.symbol);
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
