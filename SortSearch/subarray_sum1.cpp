#include <iostream>
#include <set>
using namespace std;

const int mxN=2e5;
int arr[mxN];
#define ll long long
int main(){
    int n,x,ans=0;
    ll sum=0;

    set<ll> pf;
    cin>>n>>x;
    pf.insert(0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        pf.insert(sum);
        if(pf.find(sum-x)!=pf.end()) ans++;
    }
    cout<<ans<<"\n";

    return 0;
}