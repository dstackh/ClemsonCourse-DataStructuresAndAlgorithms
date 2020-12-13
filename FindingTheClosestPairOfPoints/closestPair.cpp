/*
 * Name: Smith Stackhouse
 * Date Submitted: 2/28/2020
 * Lab Section: 003
 * Assignment Name: Lab 6 - Finding the Closest Pair of Points
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    double x;
    double y;
};

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/


//use this to compute the distance between two points
double compDistance(point pt1, point pt2)
{
    double tempX = pt1.x - pt2.x;
    double tempY = pt1.y - pt2.y;
    
    tempX = tempX * tempX;
    tempY = tempY * tempY;
    
    double total = tempX + tempY;
    
    total = sqrt(total);
    
    return total;
}



double closestPair(string filename)
{
    //Reading the input file
    ifstream inFile(filename);
    if(!inFile)
    {
        cout << "File could not be found\n";
        exit(0);
    }
    int totalPoints = 0;
    inFile >> totalPoints;
    int b = sqrt(totalPoints);
    
    
    //initialize the array set of points
    vector<vector<vector<point>>> grid(b, vector<vector<point>>(b));
    
    
    //Reading the rest of the input
    for(int i = 0; i < totalPoints; i++)
    {
        point tmp;
        inFile >> tmp.x;
        inFile >> tmp.y;
        
        double tmpDoubX = tmp.x * b;
        double tmpDoubY = tmp.y * b;
        
        int tmpIntX = (int) tmpDoubX;
        int tmpIntY = (int) tmpDoubY;
        
        //grid[(unsigned int)tempX*b][(unsigned int)tempY*b].push_back(tmp);
        grid[tmpIntX][tmpIntY].push_back(tmp);
    }
    
    
    
    //For each point compare it to all the points within its cell and the 8 adjacent cells; remember the smallest distance obtained during this process
    double minDistance = 1.0;
    double tempDist = 0.0;
    for(int a = 0; a < b; a++)
    {
        
        for(int i = 0; i < b; i++)
        {
            //need a case to check 8 adjecent cells 
            
            
            //check its own cell
            for(int j = 0; j < (int)grid[a][i].size(); j++)
            {
                for(int k = 0; k < (int)grid[a][i].size(); k++)
                {
                    if(j != k)
                    {
                        tempDist = compDistance(grid[a][i][j], grid[a][i][k]);
                        if(tempDist < minDistance)
                        {
                            minDistance = tempDist;
                        }
                    }
                }
            }
        
        
            
            //left
            if(a != 0)
            {
                for(int j = 0; j < (int)grid[a-1][i].size(); j++)
                //int or long unsigned int
                {
                    for(int k = 0; k < (int)grid[a][i].size(); k++)
                    {
                        tempDist = compDistance(grid[a][i][j], grid[a-1][i][k]);
                        if(tempDist < minDistance)
                        {
                            minDistance = tempDist;
                        }
                    }
                }
            }
        
        
            
            //right
            if(a != b-1)
            {
                for(int j = 0; j < (int)grid[a+1][i].size(); j++)
                {
                    for(int k = 0; k < (int)grid[a][i].size(); k++)
                    {
                        tempDist = compDistance(grid[a][i][j], grid[a+1][i][k]);
                        if(tempDist < minDistance)
                        {
                            minDistance = tempDist;
                        }
                    }
                }
            }
            
            
        
            //above
            if(i != 0)
            {
                
            }
        
            //below
            if(i != b-1)
            {
                
            }
        
            //top left
            if(a != 0 && i != 0)
            {
                
            }
        
            //bottom left
            if(a != b-1 && i != 0)
            {
                
            }
        
            //top right
            if(a != b-1 && i != b-1)
            {
                
            }
        
            //bottom right
            if(a != 0 && i != b-1)
            {
                
            }
        
        }
    
    }
 
    return minDistance;
}



int main()
{
    double min;
    string filename;
    cout << "File with list of points within unit square: ";
    cin >> filename;
    min = closestPair(filename);
    cout << setprecision(16);
    cout << "Distance between closest pair of points: " << min << endl;
    return 0;
}
