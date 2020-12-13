#include "IntegerArrayQueue.h"


bool IntegerArrayQueue::enqueue(int value)
{
    //Full condition
    if((back+2)%size == front)
    {
        return false;
    }
    
    //int tempFront = front;
    if(back+1 == size)
    {
        back = 0;
        array[back] = value;
        return true;
    }
    else
    {
        back = back+1;
        array[back] = value;
        return true;
    }
}




int IntegerArrayQueue::dequeue()
{
    //Empty condition
    if((back+1)%size == front)
    {
        return 0;
    }
    
    int retVal = 0;
    if(front+1 == size)
    {
        retVal = array[front];
        front = 0;
        return retVal;
    }
    else
    {
        retVal = array[front];
        array[front] = 0;
        front = front + 1;
        return retVal;
    }
    
    return 0;
}
