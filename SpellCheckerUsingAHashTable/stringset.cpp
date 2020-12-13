/*
 * Name: Smith Stackhouse
 * Date Submitted: 2/21/2020
 * Lab Section: 003
 * Assignment Name: Lab 5 - Spell Checker Using a Hash Table
 */

#include "stringset.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <list>
using namespace std;

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{

    hash<string> hasher;
    //when we need to allocate more space for the table
    if(num_elems == size)
    {
        size = size * 2;
        vector<list<string>> biggerTable(size);
        int newHalfSize = size/2;

        for(int i = 0; i < newHalfSize; i++)
        {
            for(string iterator: table[i])
            {
                int location = hasher(iterator) % size;
                biggerTable[location].push_back(iterator);
            }
        }
        table = biggerTable;
    }

    //if we do not need to allocate more space for the table
    int insert_location;
    insert_location = hasher(word) % size;
    for(string iterator: table[insert_location])
    {
        if(iterator == word)
        {
            return;
        }
    }
    table[insert_location].push_back(word);


    num_elems++;
}




bool Stringset::find(string word) const
{
    //find location to search for
    hash<string> hasher;
    int find_location = hasher(word) % size;

    //search table at find_location for word
    for(string iterator: table[find_location])
    {
        if(iterator == word)
        {
            return true;
        }
    }

    return false;
}




void Stringset::remove(string word)
{
    //find location to remove
    hash<string> hasher;
    int remove_location = hasher(word) % size;

    //search table at remove_location for word
    for(string iterator: table[remove_location])
    {
        if(iterator == word)
        {
            table[remove_location].remove(word);
            num_elems--;
            return;
        }
    }


    //cout << "\nWord was not in the table\n";
}
