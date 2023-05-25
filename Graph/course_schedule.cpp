#include <iostream>
#include <vector>
using namespace std;

const int mxN = 1e5+1;
vector<int> g[mxN+1];
vector<int> visited(mxN+1);
vector<int> ans;

bool dfs(int cur){
   
    if (g[cur].size()==0) {
        ans.push_back(cur);
        visited[cur] = 2;
        return false;
    }
    bool failed=false;
    visited[cur] = 1;
    for(int aj:g[cur]){
        if(visited[aj]==1) {
            return true;
        }
        else if(visited[aj]==0) failed |= dfs(aj);
    }
    ans.push_back(cur);
    visited[cur] = 2;
    
    return failed;

}
int main(){
    int n,m,a,b;
    bool fail=false;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        cin>>a>>b;
        g[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        if(visited[i]==0) {
            fail = dfs(i);
            if(fail) {
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for(int i=n-1;i>=0;i--) cout<<ans[i]<<" ";
    

    return 0;
}