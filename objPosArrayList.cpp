#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

// follwoing tutorial and lec videos...

objPosArrayList::objPosArrayList() // constructor
{
    aList = new objPos[ARRAY_MAX_CAP]; // 200 elements on the heap
    sizeList = 0;                      // no valid element in list upon starting
    sizeArray = ARRAY_MAX_CAP;         // array capacity should be max
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; // [] cause aList is an array
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // move elements to the back to make space at the front 

    for(int i = sizeList; i > 0; i--)
    {
        aList[i].setObjPos(aList[i-1]);
    }

    if(sizeList != sizeArray)
    {
        aList[0].setObjPos(thisPos);
        sizeList++;
    }

}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList != sizeArray)
    {
        aList[sizeList++].setObjPos(thisPos);
    }
}

void objPosArrayList::removeHead()
{
    if(sizeList > 0)
    {
        for(int i = 0; i < sizeList - 1; i++)
        {
            aList[i].setObjPos(aList[i+1]); 
        }
    }
    sizeList--;
}

void objPosArrayList::removeTail()
{
    if(sizeList > 0)
    {
        sizeList--; // tail is at the end so just take out the last elemeny by decrementing
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[sizeList-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}