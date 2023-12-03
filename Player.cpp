#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* food)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // feature 2 -- create reference to food
    mainFoodRef = food;

    // more actions to be included

    objPos tempPos; // create temp and initialize 
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX() /2,mainGameMechsRef->getBoardSizeY() /2,'*'); // initializing

    // heap -- deallocate 

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos); // insert as parameter

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

// feature 3 iteration 3

bool Player::CheckSelfCollision()
{
    objPos HeadPos;
    playerPosList->getHeadElement(HeadPos);

    objPos BodyPos;

    for(int i = 1; i < playerPosList->getSize(); i++)
    {
        playerPosList->getElement(BodyPos, i);

        if(HeadPos.x == BodyPos.x && HeadPos.y == BodyPos.y)
        {
            return true;
        }
    }

    return false;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  

    char input = mainGameMechsRef->getInput(); 

    switch(input) // change input to coordinate with gamemech
    {
        case 32: // space bar is the exit key to force end game
            mainGameMechsRef->setExitTrue(); // exit key
            break;

        case 'w': // up
        case 'W': // to account for capslock accidentally being on
            if(myDir != DOWN){ 
                myDir = UP;    
            } break;

        case 's': // down
        case 'S':
            if(myDir != UP){
                myDir = DOWN;
            } break;

        case 'a': // left
        case 'A':
            if(myDir != RIGHT){
                myDir = LEFT;
            }  break; 

        case 'd': // right
        case 'D':
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

    objPos currFood; // holding info of current food position
    mainFoodRef->getFoodPos(currFood);

    // made changes to boundaries cause wraparound not working?
    
    if(myDir == UP){ // w = UP
        currHead.y--; 
        if(currHead.y <=  0){ // wraparound logic implementation 
            currHead.y = mainGameMechsRef->getBoardSizeY() - 2; // - 2 because index is size - 1,
                                                                // and last element is # so - 2
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
    
    // iteration 3 feature 2

    if(CheckSelfCollision())
    {
        mainGameMechsRef->setLoseTrue(); // to show lose message
        mainGameMechsRef->setExitTrue(); // to end game
    }
    
    if(currFood.x == currHead.x && currFood.y == currHead.y) // checking for collision
    {
        playerPosList->insertHead(currHead);
        mainFoodRef->generateFood(playerPosList);
    }

    else
    {
        // new current head should be inserted to the head of the list,

        playerPosList->insertHead(currHead);

        // then remove tail

        playerPosList->removeTail();
    }
    

}

