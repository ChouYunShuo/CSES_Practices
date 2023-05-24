#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long ll;
typedef std::pair<ll,ll> P;
using namespace std;

int main(){
    int n,m,k,a,b,c;
    cin>>n>>m>>k;
    vector<P> g[n+1];
    priority_queue<ll> topk[n+1]; // max heap
    priority_queue<P, vector<P>,greater<P> > pq; // min heap
    vector<ll> ans;

    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
    }

    topk[1].push(0);
    pq.push(make_pair(0,1)); //reverse first dist, second node

    while(!pq.empty()){
        auto cv = pq.top().first, cn = pq.top().second;
        pq.pop();
        if(cv>topk[cn].top()) continue;

        for(auto& aj:g[cn]){
            ll temp = cv+aj.second;
            if(topk[aj.first].size()<k){
                topk[aj.first].push(temp);
                pq.push(make_pair(temp,aj.first));
            }else if(temp<topk[aj.first].top()){
                topk[aj.first].push(temp);topk[aj.first].pop();
                pq.push(make_pair(temp,aj.first));
            }
        }
    }

    while(!topk[n].empty()){
        ans.push_back(topk[n].top());
        topk[n].pop();
    }

    for(int i=k-1;i>=0;i--) cout<<ans[i]<<" ";

    return 0;
}