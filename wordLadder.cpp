#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<string> V; //words from wordlist05.txt

//Global variables for bfs distance, bfs predecessor, and neighboring nodes
//Should be unordered_map type
unordered_map<string, string> pred;           // predecessor state we came from
unordered_map<string, int> dist;             // distance (# of hops) from source node
unordered_map<string, vector<string>> nbrs;   // vector of neighboring states

//check if words differ by 1 letter
int isAdj(string a, string b) 
{ 
    int count = 0; 
    for (int i = 0; i < a.length(); i++) { 
        if (a[i] != b[i]) 
            count++; 
    } 
    if (count == 1)
        return 1;
    else if (count == 2)
        return 2;
    else if (count == 3)
        return 3;
    else if (count == 4)
        return 4;
    else
        return false;
}

void search(string source_node) {
    queue<string> to_visit;
    to_visit.push(source_node);
    //visited[source_node] = true;
    dist[source_node] = 0;
    while (!to_visit.empty()) {
        string curnode = to_visit.front();
        to_visit.pop();
    for (auto& n : nbrs[curnode])
    if (dist.count(n) == 0) {
        to_visit.push(n);
	    pred[n] = curnode;
	    dist[n] = 1 + dist[curnode];
	    //visited[n] = true;
	    
    }
  }
}

void calculatePath(string d, vector<string> &path) {
    if (pred.count(d) == 1)
        calculatePath(pred[d], path);
    path.push_back(d);
}


//Implement breadth-first search, refer to Lab 10

void wordLadder(string s, string t, int &steps, vector<string> &p)
{
    string x;
    
    ifstream inFile;
    inFile.open("wordlist05.txt");
  
    if (!inFile) {
        cerr << "Unable to open word list file";
        exit(1);   // call system to stop
    }
    
    while (inFile >> x) {
        V.push_back(x);
        cout << V.back() << "\n";
    }
    
    inFile.close();
    
    for (int i=0; i<V.size(); i++) {
        for (int j=0; j<V.size(); j++) {
            if(isAdj(V[i], V[j]) == 1) {
                nbrs[V[i]].push_back(V[j]);
                nbrs[V[j]].push_back(V[i]);
            }
        }
    }
    search(s);
    if (dist.count(t) == 0)
        steps = 0;
    else {
        steps = dist[t];
        calculatePath(t, p);
    }
}


int main(void)
{
    int steps = 0;
    string s, t;
    vector<string> path;
    
    cout << "Source: ";
    cin >> s;
    
    cout << "Target: ";
    cin >> t;
    
    wordLadder(s, t, steps, path);
    
    if (steps == 0)
    {
      cout << "No path!\n";
    }
    else
    {
      cout << "Steps: " << steps << "\n\n";
      for (int i=0; i<path.size(); i++)
      {
          cout << path[i] << endl;
      }
    }
    return 0;
}