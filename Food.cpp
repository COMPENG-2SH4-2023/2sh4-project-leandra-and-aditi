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


// double check this
// I think this works - test until you get to atleast 22 since 
// thats when the overlap usually occurs
        // got up to 30 with no overlap

void Food::generateFood(objPosArrayList* blockList) // upgraded in iteration 3
{
    srand(time(NULL));
    
    objPos blockOff; // used blockoff as name so dont have to rewite parts of code

    bool noFood = true;

    while(noFood)
    {

        int x = mainGameMechsRef->getBoardSizeX();
        int y = mainGameMechsRef->getBoardSizeY();


        int x_candidate = (rand() %  (x- 2)) + 1;
        int y_candidate = (rand() %  (y - 2)) + 1;

        noFood = false; // we now have food generated so break out of loop

    // validate

        // feature 2 - change to now go through each element in blockList -- add a for loop

        for(int i = 0; i < blockList->getSize(); i++)
        {
        
            blockList->getElement(blockOff, i);
            if(x_candidate == blockOff.x && y_candidate == blockOff.y) 
            {
                noFood = true; // no food is positions are equal
                break;
            }
        }

        foodPos.x = x_candidate;
        foodPos.y = y_candidate;
        foodPos.symbol = 'o';

        // putting the noFood = false here was still causing food under snake?
        // causing issues before the x and y stuff too -- so added it after and it seems to be working
    }
}
    

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x,foodPos.y,foodPos.symbol);
}