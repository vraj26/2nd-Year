#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; //gives me MAXCAP elements on heap
    arrayCapacity = ARRAY_MAX_CAP; //should be max
    listSize = 0; //no valid element in list within startup
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; // remember to use delete[] to call destructors of all isntances in array
    //otherwise only first element will be delted which leads to leak
}

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{

    //error check
    //check if list size is at capcaity, if yes, at capacity, don't insert
    if(listSize == arrayCapacity){
        return;
    }
    for(int i =listSize; i >0; i--){
        aList[i].setObjPos(aList[i-1]); // object position at previous element
        //shuffles all elements towards tail
    }

    aList[0].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize == arrayCapacity){
        return;
    }
    aList[listSize++] = thisPos;
}

void objPosArrayList::removeHead()
{

    if(listSize<=0){ //error catching
        return;
    }
    //grab element i+1 and overwrite with i (shuffle left to remove head)
    for(int i = 0; i < listSize-1; i ++){
        aList[i].setObjPos(aList[i+1]);
    }

    listSize--;

    //dont physically delete the value in the OG last slot
    //lazy deletion
}

void objPosArrayList::removeTail()
{
   
    if(listSize<=0){ //error catching
        return;
    }
    listSize--; //last guy in the lst gets deleted automatically
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    //figure out
    if(index >=0 && index < arrayCapacity){
        returnPos = aList[index];
    }
    else{
        return;
     }
}

//Once passed all test cases, copy paste .h and this .cpp file into the project
//After that should be done
