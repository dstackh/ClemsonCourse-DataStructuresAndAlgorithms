/*
 * Name: Smith Stackhouse
 * Date Submitted: 2/21/2020
 * Lab Section: 003
 * Assignment Name: Lab 5 - Spell Checker Using a Hash Table
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 #include <list>
 #include <iterator>
 using namespace std;
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 
 int main()
 {
     Stringset wordlist;
     loadStringset(wordlist, "wordlist.txt");
     spellcheck(wordlist, "lake");
     
     return 0;
 }
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 
 
 
 
 void loadStringset(Stringset& words, string filename)
 {
    ifstream inFile(filename);
    string tempStr;
    while(inFile)
    {
        inFile >> tempStr;
        words.insert(tempStr);
    }
    
    inFile.close();
 }
 
 
 
 vector<string> spellcheck(const Stringset& words, string word)
 {
    vector<string> spellCheckVec;
    string tempWord = word;
    bool wordCheck = false;
    
    for(int i = 0; i < (int)word.length(); i++)
    {
        for(int a = 0; a < 26; a++)
        {
            wordCheck = false;
            tempWord[i] = tempWord[i] + 1;
            if(tempWord[i] == 123)
            {
                tempWord[i] = 97;
            }
            
            wordCheck = words.find(tempWord);
            
            if(wordCheck)
            {
                if(tempWord != word)
                {
                    spellCheckVec.push_back(tempWord);
                }
            }
        }
    }
    
    return spellCheckVec;
 }
 
