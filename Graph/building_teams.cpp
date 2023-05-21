#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > graph(n+1);
    vector<int> color(n+1,0);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(color[i]!=0) continue;
        queue<int> q;
        q.push(i);
        color[i] = 1;
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(auto aj:graph[cur]){
                if(color[cur]==color[aj]){
                    cout<<"IMPOSSIBLE\n";
                    return 0;
                }
                if(color[aj]==0) {
                    q.push(aj);
                    color[aj] = color[cur]==1? 2:1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<color[i]<<" ";

    return 0;
}