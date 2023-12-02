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


// Leandra double check this
// I think this work - test until you get to atleast 22 since 
// thats when the overlap usually occurs
        // got up to 30 with no overlap

void Food::generateFood(objPosArrayList* blockList) // upgraded in iteration 3
{
    srand(time(NULL));
    
    objPos blockOff; // used blockoff as name so dont have to rewite parts of code

    bool drawn = true;

    while(drawn)
    {

        int x = mainGameMechsRef->getBoardSizeX();
        int y = mainGameMechsRef->getBoardSizeY();


        int x_candidate = (rand() %  (x- 2)) + 1;
        int y_candidate = (rand() %  (y - 2)) + 1;

        drawn = false; // to fix overlap with body -- not drawn

    // validate

        // feature 2 - change to now go through each element in blockList -- add a for loop

        for(int i = 0; i < blockList->getSize(); i++)
        {
        
            blockList->getElement(blockOff, i);
            if(x_candidate == blockOff.x && y_candidate == blockOff.y) 
            {
                drawn = true;
                break; // break out of loop
            }
        }

        foodPos.x = x_candidate;
        foodPos.y = y_candidate;
        foodPos.symbol = 'o';
    }
}
    

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x,foodPos.y,foodPos.symbol);
}