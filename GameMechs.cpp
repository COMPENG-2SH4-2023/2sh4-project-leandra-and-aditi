#include "GameMechs.h"
#include "MacUILib.h" // added to access hasChar and getChar

GameMechs::GameMechs()
{
    input = 0;
    Score = 0;
    exitFlag = false;
    LoseFlag = false;
    boardSizeX = 30; // default board size
    boardSizeY = 15; 


}

GameMechs::~GameMechs()
{
    // ok to be empty 
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    Score = 0;
    exitFlag = false;
    LoseFlag = false;
    boardSizeX = boardX; // takes input dimensions
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

void GameMechs::incrementScore(objPosArrayList* SizeList)
{
    int listSize = SizeList->getSize();
    Score = listSize - 1; // - 1 cause already 1 * exists when game begins

    // Leandra double check this 

}
