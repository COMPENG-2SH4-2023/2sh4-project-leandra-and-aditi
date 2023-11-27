#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000


GameMechs* myGM;
Player* myPlayer;


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

}

void GetInput(void)
{
    myGM->getInput();
   
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    myGM->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    int i;
    int j;

    objPos tempPos;
    myPlayer->getPlayerPos(tempPos); // get the player pos

    for(i = 0; i < myGM->getBoardSizeY(); i++){ // rows
    
        for(j = 0; j < myGM->getBoardSizeX(); j++){ // columns

            if(j == 0 || j == myGM->getBoardSizeX()-1 || i == 0 || i == myGM->getBoardSizeY()-1){
                MacUILib_printf("%s","#");
            }

            else if(i == tempPos.y && j == tempPos.x){
                MacUILib_printf("%c", tempPos.symbol);
            }

            else{
                MacUILib_printf("%s"," ");
            }
        }

        MacUILib_printf("%s","\n");
    }

    MacUILib_printf("BoardSize: %dx%d, Player Pos: <%d, %d>, + %c\n", myGM->getBoardSizeX(), myGM->getBoardSizeY(), tempPos.x, tempPos.y, tempPos.symbol);

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
}
