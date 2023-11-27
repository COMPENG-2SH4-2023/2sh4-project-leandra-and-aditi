#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX() /2,mainGameMechsRef->getBoardSizeY() /2,'*'); // initializing
}


Player::~Player()
{
    delete [] myPlayer; 

}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list

    // iteration 1 -- currently only have 1 player position
    returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

