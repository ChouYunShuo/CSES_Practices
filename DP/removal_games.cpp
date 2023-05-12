#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int main(){
    int n;
    cin>>n;
    int arr[n+1]; 
    ll sum=0;
    vector<vector<ll> > dp(n+1, vector<ll>(n+1,0));
    for(int i=0;i<n;i++) {
        cin>>arr[i+1];
        sum+=arr[i+1];
    }

    for(int i=1;i<=n;i++){
        dp[i][i] = arr[i];
    }

    for(int g=1;g<n;g++){
        for(int i=1;i<=n-g;i++){
            dp[i][i+g] = max(arr[i+g]-dp[i][i+g-1],arr[i]-dp[i+1][i+g]);
        }
    }
    
    cout<<(sum+dp[1][n])/2<<"\n";



    return 0;
}