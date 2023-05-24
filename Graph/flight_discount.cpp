#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef std::pair<ll, ll> P;
const ll mi=1e15+7;

struct compare {
    bool operator()(const P& l, const P& r) {
        return l.second > r.second;
    }
};
vector<ll> dijkstra(vector<vector<P> > &g, int start){
    vector<ll> ans(g.size(), mi);
    
    priority_queue<P, vector<P>, compare> q;
    q.push(make_pair(start,0));

    while(!q.empty()){
        ll cn=q.top().first,cv=q.top().second;
        q.pop();
        if(cv>ans[cn]) continue;
        ans[cn] = cv;

        for(P aj:g[cn]){
            if(ans[aj.first]>ans[cn]+aj.second){
                ans[aj.first]=ans[cn]+aj.second;
                q.push(make_pair(aj.first,ans[aj.first]));
            }
        }
    }

    return ans;

}
int main(){
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<P> > g(n + 1);
    vector<vector<P> > rg(n + 1);
    vector<ll> md1(n);
    vector<ll> md2(n);

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        rg[b].push_back(make_pair(a, c));
    }

    md1 = dijkstra(g, 1);
    md2 = dijkstra(rg, n);
    // for(int i=1;i<=n;i++){
    //     cout<<md1[i]<<" ";
    // }cout<<"\n";
    // for(int i=1;i<=n;i++){
    //     cout<<md2[i]<<" ";
    // }cout<<"\n";

    ll ans=mi;

    for(int i=1;i<n;i++){
        for(auto aj:g[i]){
            ans = min(ans, md1[i]+(aj.second/2)+md2[aj.first]);
        }
    }

    cout<<ans<<"\n";


    return 0;
}