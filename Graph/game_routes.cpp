#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int mxN = 1e5;
vector<ll> dp(mxN+1);
vector<int> g[mxN+1];
vector<int> topo_order;
vector<int> indegree(mxN);

int main(){
    int m,n,a,b;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();q.pop();
        topo_order.push_back(cur);
        for(int aj:g[cur]){
            indegree[aj]--;
            if(indegree[aj]==0) q.push(aj);
        }
    }
    dp[1] = 1;

    for(int i=0;i<n;i++){
        int cur = topo_order[i];
        for(int aj:g[cur]){
            dp[aj] = (dp[aj]+dp[cur])%mod;
        }
    }

    cout<<dp[n]<<"\n";
    return 0;
}