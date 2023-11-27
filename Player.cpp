#include "Player.h"

// Developer 2 - Leandra 

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

    char input = mainGameMechsRef->getInput(); 

    switch(input) // change input to coordinate with gamemech
    {
        case 32:
            mainGameMechsRef->setExitTrue(); // exit key
            break;

        case 'w': // up
            if(myDir != DOWN){ 
                myDir = UP;    
            } break;

        case 's': // down
            if(myDir != UP){
                myDir = DOWN;
            } break;

        case 'a': // left
            if(myDir != RIGHT){
                myDir = LEFT;
            }  break; 

        case 'd': // right
            if(myDir != LEFT){
                myDir = RIGHT;
            } break;

        default:
            break;
    }       
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    if(myDir == UP){ // w = UP
        playerPos.y--; 
        if(playerPos.y == 0){ // wraparound logic implementation 
            playerPos.y = mainGameMechsRef->getBoardSizeY() - 2; 
        }
    } 

    else if(myDir == DOWN){ 
        playerPos.y++;
        if(playerPos.y == mainGameMechsRef->getBoardSizeY()){
            playerPos.y = 1; 
        }
    } 

    else if(myDir == LEFT){ 
        playerPos.x--; // x decreases as we go left
        if(playerPos.x == 0){
            playerPos.x = mainGameMechsRef->getBoardSizeX() - 2; 
        }
    } 

    else if(myDir == RIGHT){ // d = RIGHT
        playerPos.x++;
        if(playerPos.x == mainGameMechsRef->getBoardSizeX()){
            playerPos.x = 1; 
        }
    } 
}

