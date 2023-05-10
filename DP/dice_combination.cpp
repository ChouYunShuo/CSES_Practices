#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int mxN = 1e6+1;
int main(){
    int n;
    cin>>n;
    ll dp[mxN];
    ll mod = 1e9+7;
    
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    for(int i=2;i<=6;i++){
        for(int j=0;j<i;j++) dp[i]+=dp[j];
        dp[i]++;
    }
    for(int i=7;i<mxN;i++){
        for(int j=1;j<7;j++) dp[i]+=dp[i-j];
        dp[i] = dp[i]%mod;
    }
   
    cout<<dp[n]<<"\n";

    return 0;
}