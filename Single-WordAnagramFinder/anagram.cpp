/*
 * Name: Smith Stackhouse
 * Date Submitted: 3/9/2020
 * Assignment Name: Single-Word Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <algorithm>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
    unordered_map <char, int> wordMap;
    vector<string> anagWords;
    int count = 0;
    
    //create a map for the word parameter
    for(int i = 0; i < (int)word.size(); i++)
    {
        count = 0;
        for(int j = 0; j < word.size(); j++)
        {
            if(word[i] == word[j])
            {
                count++;
            }
        }
        wordMap[word[i]] = count;
    }
    
    
    //go through the wordlist.txt file and create a map for each word and compare it to the map of the word parameter 
    for(int i = 0; i < wordlist.size(); i++)
    {
        unordered_map <char, int> tempMap;
        for(int j = 0; j < wordlist[i].size(); j++)
        {
            count = 0;
            for(int a = 0; a < wordlist[i].size(); a++)
            {
                if(wordlist[i][j] == wordlist[i][a])
                {
                    count++;
                }
            }
            tempMap[wordlist[i][j]] = count;            
        }
        
        if(wordMap == tempMap)
        {
            anagWords.emplace_back(wordlist[i]);
        }
    }
    
    return anagWords;
}
