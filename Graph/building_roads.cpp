#include <iostream>
#include <vector>
using namespace std;

void dfs(int cur, vector<vector<int> >& graph, vector<vector<int> >& cnodes, vector<bool> & visited, int i){
    visited[cur] = true;
    cnodes[i].push_back(cur);
    for(int aj: graph[cur]){
        if(!visited[aj]) dfs(aj, graph, cnodes, visited, i);
    }

    return;
}
int main(){
    int n,m,cc=0;
    cin>>n>>m;

    vector<vector<int> > graph(n);
    vector<vector<int> > cnodes(n);
    vector<bool> visited(n, false);

    for(int i=0;i<m;i++){
       int a,b;
       cin>>a>>b;
       graph[a-1].push_back(b-1);
       graph[b-1].push_back(a-1);
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i, graph, cnodes,visited,cc);
            cc++;
        } 
        
    }

    cout<<cc-1<<"\n";
    for(int i=0;i<cc-1;i++){
        cout<<cnodes[i][0]+1<<" "<<cnodes[i+1][0]+1<<"\n";
    }

    return 0;
}