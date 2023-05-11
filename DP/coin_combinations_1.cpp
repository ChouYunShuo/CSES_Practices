#include <iostream>

using namespace std;

typedef long long ll;
const int mxN = 1e6+1;
ll arr[101];
ll dp[mxN];
int main(){
    int n,x;
    ll mod = 1e9+7;
    cin>>n>>x;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[arr[i]] = 1;
    }

    for(int i=1;i<mxN;i++){
        for(int j=0;j<n;j++){
            if(i>arr[j]) dp[i] += dp[i-arr[j]];
            dp[i] = dp[i]%mod;
        }
        
    }

    cout<<dp[x]<<"\n";

    return 0;
}