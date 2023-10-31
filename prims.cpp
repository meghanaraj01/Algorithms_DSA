#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findminvertex(vector<int>& weight, vector<bool>& visited, int v){
  int minvertex = -1;
  for(int i=0; i<v; i++){
    if(!visited[i] && (minvertex == -1 || weight[i] < weight[minvertex])){
      minvertex = i;
    }
  }
  return minvertex;
}

void printMst(int** graph, int v){
    vector<int> parent(v);
    vector<int> weight(v,INT_MAX);
    vector<bool> visited(v,false);
    parent[0] = -1;
    weight[0] = 0;
    for(int i=0; i<v; i++){
      //find minvertex
      int minVertex = findminvertex(weight,visited,v);
      visited[minVertex] = true;
      //explore unvisited neighbours
      for(int j=0; j<v; j++){
        if(graph[minVertex][j] != 0 && !visited[j]){
          if(graph[minVertex][j] < weight[j]){
            weight[j] = graph[minVertex][j];
            parent[j] = minVertex;
          }
        }
      }
    }
    for(int i=1; i<v; i++){
      cout<<min(parent[i],i)<<" "<<max(parent[i],i)<<" "<<weight[i]<<"\n";
    }
}


int main(){
  int v,e;
  cin>>v>>e;
  int** graph = new int*[v];
  for(int i=0; i<v; i++){
    graph[i] = new int[v];
    for(int j=0; j<v; j++){
      graph[i][j] = 0;
    }
  }

    for(int i=0; i<e; i++){
      int f,e,weight;
      cin>>f>>e>>weight;
      graph[f][e] = weight;
      graph[e][f] = weight;
    }
    printMst(graph,v);
 
}