#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int V;
    int E;
    int  u,v;
    cin>>V>>E;
    int cnt=0;

    vector<vector<int>> adj_list(V);
    vector<int> indeg(V,0);
    for(int i=0;i<E;i++){
        cin>>u>>v;
        //u-->v
        adj_list[u].push_back(v);
        indeg[v]++;
    }
    queue<int> pq;
    for(int i=0;i<V;i++){
        if(indeg[i]==0) pq.push(i);
    }
    //time complexity O(V+E)
    while(!pq.empty()){
        cnt++;
        int x=pq.front(); //we are calling before deleting
        pq.pop(); //data is not returned 
        cout<<x<<" "; 
        for(auto it:adj_list[x]){
            indeg[it]--;
            if(indeg[it]==0) pq.push(it);
        }   }
}