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

void Food::generateFood(objPos blockOff)
{
    srand(time(NULL));

    int x_candidate;
    int y_candidate;

    while(true)
    {
        int x = mainGameMechsRef->getBoardSizeX();
        int y = mainGameMechsRef->getBoardSizeY();


        x_candidate = (rand() %  (x- 2)) + 1;
        y_candidate = (rand() %  (y - 2)) + 1;

    // validate

        // if at least one of the coordinates does not match player pos -- generate 

        if(x_candidate != blockOff.x || y_candidate != blockOff.y)
        {
            foodPos.x = x_candidate;
            foodPos.y = y_candidate;
            foodPos.symbol = 'o';
            break; // after generating break out of while loop
        }
    }
}
    

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x,foodPos.y,foodPos.symbol);
}

void Food::updateFood() // for debugging purposes 
{

    char input = mainGameMechsRef->getInput(); 

    switch(input) // change input to coordinate with gamemech
    {
        case 'o':
            generateFood(foodPos);
            break;
    }       
}