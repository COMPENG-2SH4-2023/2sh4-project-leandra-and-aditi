#ifndef FOOD_H
#define FOOD_H

#include <cstdlib> //provides srand() and rand()
#include <time.h> //provides time

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h" 

using namespace std;


class Food
{
    public:
        Food(GameMechs* thisGMRef);
        ~Food(); // destructor

        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);
        void updateFood();


    private:
    
        objPos foodPos; 
        
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
    
        int **food; //heap data
    
};


#endif