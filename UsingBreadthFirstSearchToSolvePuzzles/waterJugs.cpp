/*
 * Name:Smith Stackhouse
 * Date Submitted:4/20/2020
 * Lab Section:003
 * Assignment Name: Lab 10 - Using Breadth-First Search to Solve Puzzles
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Reflects what each node represents...
// First value units of water in A, second units of water in B
typedef pair<int,int> state;

// Each string in edge_label must be one of the following:
const string actions[] = {"Fill A",
                          "Fill B",
                          "Empty A",
                          "Empty B",
                          "Pour A->B",
                          "Pour B->A"};


// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label;



// GENERIC (breadth-first search, outward from source_node)
void search(state source_node)
{
  queue<state> to_visit;
  to_visit.push(source_node);
  visited[source_node] = true;
  dist[source_node] = 0;
  
  while (!to_visit.empty()) {
    state curnode = to_visit.front();
    to_visit.pop();
    for (state n : nbrs[curnode])
      if (!visited[n]) {
	pred[n] = curnode;
	dist[n] = 1 + dist[curnode];
	visited[n] = true;
	to_visit.push(n);
      }
  }
}




// GENERIC
void print_path(state s, state t)
{
  if (s != t) {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": " << "[" << t.first << "," << t.second << "]\n";
  } else {
    cout << "Initial state: " << "[" << s.first << "," << s.second << "]\n";
  }
}



void build_graph(void)
{
  //Implement this function
  
  for(int i = 0; i <= 3; i++) 
  {
        for (int j = 0; j <= 4; j++) 
        {
            edge_label[make_pair(make_pair(i, j), make_pair(3, j))] = (actions[0]);
            nbrs[make_pair(i, j)].push_back(make_pair(3, j));
            edge_label[make_pair(make_pair(i, j), make_pair(i, 4))] = (actions[1]);
            nbrs[make_pair(i, j)].push_back(make_pair(i, 4));
            edge_label[make_pair(make_pair(i, j), make_pair(0, j))] = (actions[2]);
            nbrs[make_pair(i, j)].push_back(make_pair(0, j));
            edge_label[make_pair(make_pair(i, j), make_pair(i, 0))] = (actions[3]);
            nbrs[make_pair(i, j)].push_back(make_pair(i, 0));
            if ((i+j) < 4) 
            {
                edge_label[make_pair(make_pair(i, j), make_pair(0, j+i))] = (actions[4]);
                nbrs[make_pair(i, j)].push_back(make_pair(0, j+i));
            }
            else 
            {
                int temp = 4-j;
                edge_label[make_pair(make_pair(i, j), make_pair(i-temp, 4))] = (actions[4]);
                nbrs[make_pair(i, j)].push_back(make_pair(i-temp, 4));
            }
            if ((i+j) < 3) 
            {
                edge_label[make_pair(make_pair(i, j), make_pair(i+j, 0))] = (actions[5]);
                nbrs[make_pair(i, j)].push_back(make_pair(i+j, 0));
            }
            else 
            {
                int temp = 3-i;
                edge_label[make_pair(make_pair(i, j), make_pair(3, j-temp))] = (actions[5]);
                nbrs[make_pair(i, j)].push_back(make_pair(3, j-temp));
            }
        }
    }
  
}



int main(void)
{
  build_graph();

  state start = make_pair(0,0);
  
  for (int i=0; i<5; i++)
    nbrs[make_pair(i,5-i)].push_back(make_pair(-1,-1));
  search (start);
  if (visited[make_pair(-1,-1)]) 
    print_path (start, pred[make_pair(-1,-1)]);
  else
    cout << "No path!\n";
  
  return 0;
}
