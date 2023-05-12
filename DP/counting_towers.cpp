#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int mxN = 1e6;
ll dp[mxN][2];

int main(){

    int t;
    int mod = 1e9+7;
    cin>>t;
    vector<int> inputs(t);

    dp[0][0] = 1;
    dp[0][1] = 1;

    for(int i=1;i<mxN;i++){
        dp[i][0] = ((dp[i-1][0]*4)%mod+ dp[i-1][1])%mod;//cur is cut | 
        dp[i][1] = (dp[i-1][1]*2%mod+ dp[i-1][0])%mod;

    }
   
    for(int i=0;i<t;i++){
        cin>>inputs[i];
    }
    for(int i=0;i<t;i++){
        cout<<(dp[inputs[i]-1][0] + dp[inputs[i]-1][1])%mod<<"\n";
    }


    return 0;
}