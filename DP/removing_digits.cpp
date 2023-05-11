#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int mxN = 1e6;
int main(){
    int n;
    cin>>n;
    vector<int> dp(1e6, INT_MAX);

    for(int i=0;i<10;i++){
        dp[i] = 1;
    }

    for(int i=10;i<=n;i++){
        int cur = i;
        while(cur>0){
            dp[i] = min(dp[i], dp[i-cur%10]);
            cur/=10;
        }
        dp[i]+=1;
    }

    cout<<dp[n]<<"\n";




    return 0;
}