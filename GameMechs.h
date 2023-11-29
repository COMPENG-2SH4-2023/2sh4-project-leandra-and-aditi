#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib> // provides srand() and rand()
#include <time.h> // provides time

#include "objPos.h"
#include "objPosArrayList.h" 

using namespace std;


class GameMechs 
{
    private:
        char input;
        bool exitFlag;

        // added faeatures

        bool LoseFlag;
        
        int boardSizeX;
        int boardSizeY;

        int Score;

        int** myGM; // heap data member

    public:
        GameMechs();
        ~GameMechs(); // destructor
        GameMechs(int boardX, int boardY);
        
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
        void incrementScore(objPosArrayList* SizeList); // based on the size of the "snake" set the score

};

#endif