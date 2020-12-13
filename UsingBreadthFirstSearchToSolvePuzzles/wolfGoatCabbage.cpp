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
// int with each bit == 0 left of river, bit == 1 right of river
typedef int state;

// Bit position representation for wolf/goat/cabbage/me
bool bit(int x, int i)
{
    return (x>>i) & 1;
}
const int wolf=0, goat=1, cabbage=2, me=3;


// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label;



// GENERIC (breadth-first search, outward from curnode)
void search(state source_node)
{
  queue<state> to_visit;
  to_visit.push(source_node);
  visited[source_node] = true;
  dist[source_node] = 0;

  while (!to_visit.empty())
  {
    state curnode = to_visit.front();
    to_visit.pop();
    for (state n : nbrs[curnode])
    {
        if (!visited[n])
        {
            pred[n] = curnode;
	        dist[n] = 1 + dist[curnode];
	        visited[n] = true;
	        to_visit.push(n);
        }
    }
  }
}


//prints current state of river
string state_string(state s)
{
  string items[4] = { "wolf", "goat", "cabbage", "you" }, result = "";

  for (int i=0; i<4; i++)
    if (!bit(s, i)) result += items[i] + " ";
  result += " |river| ";

  for (int i=0; i<4; i++)
    if (bit(s, i)) result += items[i] + " ";

  return result;
}



// GENERIC
void print_path(state s, state t)
{

  if (s != t)
  {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": " << state_string(t) << "\n";
  }
  else
  {
    cout << "Initial state: " << state_string(s) << "\n";
  }
}




string neighbor_label(int s, int t)
{
  string items[3] = { "wolf", "goat", "cabbage" }, which_cross;
  if (bit(s,me) == bit(t,me)) return "";  // must cross river
  int cross_with = 0;
  for (int i=0; i<3; i++)
  {
    if (bit(s,i) != bit(t,i) && bit(s,i)==bit(s,me))
    {
        cross_with++;
        which_cross = items[i];
    }
    if (bit(s,i) != bit(t,i) && bit(s,i)!=bit(s,me))
    {
        return "";
    }

  }
  if (cross_with > 1) return "";
  if (cross_with == 0) return "Cross alone";
  else return "Cross with " + which_cross;
}


bool check (int state)
{
    if ((bit(state,wolf) == bit(state,goat)) && (bit(state,wolf) != bit(state,me)))
    {
        return false;
    }
    else if ((bit(state,goat) == bit(state,cabbage)) && (bit(state,cabbage) != bit(state,me)))
    {
        return false;
    }
    else
    {
        return true;
    }
}


void build_graph(void)
{
  for(int i = 0; i < 16; i++)
  {
        for (int j = 0; j < 16; j++)
        {
            if ((check(j)) && (neighbor_label(i,j) != ""))
            {
                nbrs[i].push_back(j);
                edge_label[make_pair(i, j)] = neighbor_label(i,j);
            }
        }
    }
}




int main(void)
{
  build_graph();

  state start = 0, end = 15;

  search(start);
  if (visited[end])
    print_path (start, end);
  else
    cout << "No path!\n";

  return 0;
}
