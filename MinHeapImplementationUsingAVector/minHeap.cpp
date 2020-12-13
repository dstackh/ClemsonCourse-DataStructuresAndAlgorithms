#include <vector>
#include "minHeap.h"

using namespace std;

/*
class minHeap
{
    private:
        vector<int> heap;*/

        void minHeap::siftUp(int pos)
        {
            if(pos == 0)
            {
                return;
            }


            int secPos = (pos-1)/2;

            if(heap[secPos] > heap[pos])
            {
                int temp = heap[secPos];
                heap[secPos] = heap[pos];
                heap[pos] = temp;
                siftUp(secPos);
            }
        }


        void minHeap::siftDown(int pos)
        {
            int length = heap.size();
            int leftInd = 2*pos + 1;
            int rightInd = 2*pos + 2;

            if(leftInd >= length)
            {
                return;
            }


            int minIndex = pos;

            if(heap[pos] > heap[leftInd])
            {
                minIndex = leftInd;
            }

            if((rightInd < length) && (heap[minIndex] > heap[rightInd]))
            {
                minIndex = rightInd;
            }

            if(minIndex != pos)
            {
                int temp = heap[pos];
                heap[pos] = heap[minIndex];
                heap[minIndex] = temp;
                siftDown(minIndex);
            }
        }


    //public:
        minHeap::minHeap(vector<int> data)
        {
            for(int i = 0; i < data.size(); i++)
            {
                heap.push_back(data[i]);
            }

            int length = heap.size() - 1;
            while(length >= 0)
            {
                siftDown(length);
                length--;
            }
        }


        void minHeap::insert(int value)
        {
            int length = heap.size();
            heap.push_back(value);
            siftUp(length);
        }


        int minHeap::removeMin()
        {
            int length = heap.size();
            if(length == 0)
            {
                return 0;
            }
            else
            {
                int temp = heap[0];
                heap[0] = heap[length - 1];
                heap.pop_back();
                siftDown(0);
                return temp;
            }

        }


//};
