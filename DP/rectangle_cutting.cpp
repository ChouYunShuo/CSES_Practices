#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;

    vector<vector<int> > dp(a+1, vector<int>(b+1,0));
    for(int i=1;i<=a;i++){
        dp[i][1] = i-1;
    }
    for(int i=1;i<=b;i++){
        dp[1][i] = i-1;
    }
    
    for(int i=2;i<=a;i++){
        for(int j=2;j<=b;j++){
            int mn = INT_MAX;
            if (i==j) mn = 0;
            for(int k=1;k<i;k++){
                mn = min(mn, dp[k][j]+dp[i-k][j]+1);
            }
            for(int k=1;k<j;k++){
                mn = min(mn, dp[i][k]+dp[i][j-k]+1);
            }
            dp[i][j] =  mn;
        }
    }

    cout<<dp[a][b]<<"\n";

    return 0;
}