/*
 * Name: Smith Stackhouse
 * Date Submitted: 2/10/2020
 * Lab Section: 003
 * Assignment Name: Lab 3 - Finding Groups Using Recursion
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Represents an occupied square in the grid
//Do not modify the GridSquare class or its member functions
class GridSquare
{
    private:
        int row, col;
    public:
        GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square
        GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square
        //Compare with == operator, used in test cases
        bool operator== (const GridSquare r) const
        {
            if ((row == r.row) && (col == r.col))
            {
                return true;
            }
            return false;
        }
        int getRow() { return row; } //return row value
        int getCol() { return col; } //return column value
        //Output using << operator, used in Grouping::printGroups()
        friend ostream& operator<< (ostream& os, const GridSquare obj);
};

//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

/*
Groups squares in 10x10 grid upon construction
Additional private helper functions may be added
Need to implement the constructor that takes a file name
as well as findGroup
The findGroup function's parameter list may be changed based
on how the function is implemented
*/
class Grouping
{
    private:
        int grid[10][10];
        vector<vector<GridSquare>> groups;
    public:
        Grouping() : grid{},groups() {} //Default constructor, no groups
        Grouping(string fileName); //Implement this function
        void findGroup(int r, int c); //Implement this function (recursive)
        void printGroups() //Displays grid's groups of squares
        {
            for(int g=0; g<groups.size(); g++)
            {
                cout << "Group " << g+1 << ": ";
                for(int s=0; s<groups[g].size(); s++)
                {
                    cout << " " << groups[g][s];
                }
                cout << endl;
            }
        }
        vector<vector<GridSquare>> getGroups() //Needed in unit tests
        {
            return groups;
        }
};

//Implement the (parameterized) constructor and findGroup functions below
Grouping::Grouping(string fileName)
{
    char tempChar;
    ifstream inFile;
    inFile.open(fileName);
    
    //creating a game board that the computer can manipulate easier
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            inFile >> tempChar;
            
            if(tempChar == '.')
            {
                grid[i][j] = 1;
            }
            else if(tempChar == 'X')
            {
                grid[i][j] = 2;
            }
        }
    }
    
    
    //finding groups
    for(int a = 0; a < 10; a++)
    {
        for(int b = 0; b<10; b++)
        {
            if(grid[a][b] == 2)
            {
                groups.emplace_back();
                findGroup(a, b);
            }
        }
    }
    
    
}




void Grouping::findGroup(int r, int c)
{
    if(grid[r][c] == 1)
    {
        return;
    }
    else if(grid[r][c] == 2)
    {
        grid[r][c] = 3;
        groups.back().emplace_back(r, c);
        
        if(r > 0)
        {
            findGroup(r - 1, c);
        }
        if(r < 9)
        {
            findGroup(r + 1, c);
        }
        if(c > 0)
        {
            findGroup(r, c - 1);
        }
        if(c < 9)
        {
            findGroup(r, c + 1);
        }
        
    }
    
}





//Simple main function to test Grouping
int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();
    
    return 0;
}
