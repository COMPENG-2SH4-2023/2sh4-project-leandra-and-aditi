#include "GameMechs.h"
#include "MacUILib.h" // added to access hasChar and getChar

// Developer 1 - Aditi

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    LoseFlag = false;
    boardSizeX = 30; // default board size
    boardSizeY = 15; 

}

GameMechs::~GameMechs()
{
    delete [] myGM; // delete created heap data members
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    LoseFlag = false;
    boardSizeX = boardX; // default board size
    boardSizeY = boardY;
}


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;

}

char GameMechs::getInput()
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

bool GameMechs::getLoseFlagStatus()
{
    return LoseFlag;
}

void GameMechs::setLoseTrue()
{
    LoseFlag = true;
}

int GameMechs::getScore()
{
    return Score;
}

void GameMechs::incrementScore()
{
    Score++;
}