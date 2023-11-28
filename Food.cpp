#include "Food.h"


using namespace std;

Food::Food(GameMechs* thisGMRef) // using the same guidelines as player.cpp
{
    mainGameMechsRef = thisGMRef;

    foodPos.setObjPos(-1, -1, 'o'); //initialize foodPos outside game board
}

Food::~Food()
{
    delete[] food;
}

void Food::generateFood(objPosArrayList* blockList) // upgraded in iteration 3
{
    srand(time(NULL));
    
    objPos blockOff; // used blockoff as name so dont have to rewite parts of code

    int x_candidate;
    int y_candidate;

    bool drawn = true;

    while(drawn)
    {
        int x = mainGameMechsRef->getBoardSizeX();
        int y = mainGameMechsRef->getBoardSizeY();


        x_candidate = (rand() %  (x- 2)) + 1;
        y_candidate = (rand() %  (y - 2)) + 1;

    // validate

        // feature 2 - change to now go through each element in blockList -- add a for loop

        for(int i = 0; i < blockList->getSize(); i++)
        
            blockList->getElement(blockOff, i);
            if(x_candidate != blockOff.x || y_candidate != blockOff.y) // if at least one of the coordinates 
                                                                       // does not match player pos -- generate 
            {
                foodPos.x = x_candidate;
                foodPos.y = y_candidate;
                foodPos.symbol = 'o';
                drawn = false;
                break; // after generating break out of while loop

            }
        
    }
}
    

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x,foodPos.y,foodPos.symbol);
}