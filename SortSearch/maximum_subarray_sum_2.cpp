#include <iostream>
#include <set>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    ll ans = LLONG_MIN;
    vector<ll> pf(n+1);
    multiset<ll> pf_range;


    for(int i=1;i<=n;i++){
       int x;
       cin>>x;
       pf[i] = pf[i-1]+x;
    }


    for(int i=a;i<=n;i++){
       
        if(i>b) {
            pf_range.erase(pf_range.find(pf[i-b-1]));
        }
        pf_range.insert(pf[i-a]);
        ans = max(ans, pf[i]-*pf_range.begin());
    }

    cout<<ans<<"\n";
    
    return 0;    
}