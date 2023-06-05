#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int maxN = 1e5+1;
vector<int> g[maxN];
vector<int> rg[maxN];
vector<bool> visited(maxN);
stack<int> q;
vector<int> comp(maxN,0);
int ccnt=0;

void dfs1(int c){
    visited[c] = true;
    for(auto aj:g[c]){
        if(!visited[aj]) {
            dfs1(aj);
        }
    }
    q.push(c);
}

void dfs2(int c){
    comp[c] = ccnt;
    for(auto aj:rg[c]){
        if(comp[aj]==0) {
            dfs2(aj);
        }
    }
}
int main(){
    int n,m,a,b;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]) {
            dfs1(i);
        }
    }
    while(!q.empty()){
        int cur = q.top(); q.pop();
        if(comp[cur]==0) {
            ccnt++;
            dfs2(cur); 
        }
    }

    cout<<ccnt<<'\n';
    for(int i=1;i<=n;i++) cout<<comp[i]<<' ';


    return 0;
}