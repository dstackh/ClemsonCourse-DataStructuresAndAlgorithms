/*
 * Name: Smith Stackhouse
 * Date Submitted: 4/7/2020
 * Lab Section: 003
 * Assignment Name: Lab 9 - Using Recursion to Solve the N-Queens Problem
 */

#include <iostream>
#include <vector>

using namespace std;

void boardTracker(int num, int row, bool *currLine, bool *temp1, bool *temp2, int &update);

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions
    
    int update = 0;
    int totN = n * 2;
    bool temp1[totN];
    bool temp2[totN];
    bool halfTemp[n];
    int a = 0;
    int b = 0;
    
    while(a < n)
    {
        halfTemp[a] = false;
        a++;
    }
    
    while(b < totN)
    {
        temp1[b] = false;
        temp2[b] = false;
        b++;
    }
    
    boardTracker(n, 0, halfTemp, temp1, temp2, update);
    return update;
}


void boardTracker(int num, int row, bool *currLine, bool *temp1, bool *temp2, int &update)
{
    if(row == num)
    {
        update++;
        return;
    }
    
    for(int j = 0; j < num; j++)
    {
        if(currLine[j] || temp1[j+row] || temp2[j - row + num])
        {
            continue;
        }
        
        currLine[j] = true;
        temp1[j+row] = true;
        temp2[j - row + num] = true;
        
        boardTracker(num, row+1, currLine, temp1, temp2, update);
        currLine[j] = false;
        temp1[j+row] = false;
        temp2[j-row+num] = false;
        
    }
    
    
}


int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}
