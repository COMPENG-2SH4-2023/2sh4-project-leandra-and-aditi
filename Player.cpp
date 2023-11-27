#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included

    objPos tempPos; // create temp and initialize 
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX() /2,mainGameMechsRef->getBoardSizeY() /2,'@'); // initializing

    // heap -- deallocate 

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos); // insert as parameter

    // for debugging

    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
}


Player::~Player()
{
    delete [] myPlayer; 
    delete playerPosList;

}


objPosArrayList* Player::getPlayerPos()
{
    // player is composed of objPosArrayList -- for snake body
    // return the reference to playpos array list

    return playerPosList;
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

    // upgrading for iteration 3 - snake body

    objPos currHead; // holding position info of current head
    playerPosList->getHeadElement(currHead);

    // made changes to boundaries cause wraparound not working?
    
    if(myDir == UP){ // w = UP
        currHead.y--; 
        if(currHead.y <=  0){ // wraparound logic implementation 
            currHead.y = mainGameMechsRef->getBoardSizeY() - 2; 
        }
    } 

    else if(myDir == DOWN){ 
        currHead.y++;
        if(currHead.y > mainGameMechsRef->getBoardSizeY() - 2){
            currHead.y = 1; 
        }
    } 

    else if(myDir == LEFT){ 
        currHead.x--; // x decreases as we go left
        if(currHead.x <= 0){
            currHead.x = mainGameMechsRef->getBoardSizeX() - 2; 
        }
    } 

    else if(myDir == RIGHT){ // d = RIGHT
        currHead.x++;
        if(currHead.x > mainGameMechsRef->getBoardSizeX() - 2){
            currHead.x = 1; 
        }
    } 

    // new current head should be inserted to the head of the list,

    playerPosList->insertHead(currHead);

    // then remove tail

    playerPosList->removeTail();

}

