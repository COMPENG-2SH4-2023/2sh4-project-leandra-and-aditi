#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib> // provides srand() and rand()
#include <time.h> // provides time

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs 
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        bool LoseFlag; // added faeatures
        
        int boardSizeX;
        int boardSizeY;

        int Score;

        int** myGM; // heap data member

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // destructor
        
        bool getExitFlagStatus();
        void setExitTrue();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();

        // added features 

        bool getLoseFlagStatus();
        void setLoseTrue();

        int getScore();
        void incrementScore();

      

};

#endif