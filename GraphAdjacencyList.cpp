#include<bits/stdc++.h> 
using namespace std; 
   
// graph class
class Graph 
{ 
int V;    // No. of vertices 
list<int> *adjList;    // adjacency lists // adjList has many sub linked lists
public: 
Graph(int V)  //graph Constructor 
    {
this->V = V; 
adjList = new list<int>[V]; //the size of adjList is V
    }
void addEdge(int v, int w) // add an edge to graph 
    {
adjList[v].push_back(w); // Add w to v’s list. directed graph // the linked list with v index adds the last w in the list
    }
 

  void printAdjList(){
    //Iterate over all the vertices 
    for(int i=0;i<V;i++){
        cout<<"Vertex "<<i<<"-> ";
   for(int nbr:adjList[i]){ //linked list adjList
      cout<<nbr<<" ,";
   }
    cout<<endl;
    }
  } 

}; 
//main program
int main() 
{ 
    Graph gidfs(5);  //create graph 
gidfs.addEdge(0, 1); 
gidfs.addEdge(0, 2); 
gidfs.addEdge(0, 3);
gidfs.addEdge(1, 2); 
gidfs.addEdge(2, 4);
gidfs.addEdge(3, 3); 
gidfs.addEdge(4, 4);
  

  gidfs.printAdjList();

   
return 0; 
}