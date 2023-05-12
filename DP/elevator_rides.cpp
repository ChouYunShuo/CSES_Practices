#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,x;

    cin>>n>>x;
    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    vector<pair<int,int> > dp(1<<n);

    dp[0] = make_pair(1,0);
    
    for(int i=1;i<(1<<n);i++){
        dp[i] = make_pair(n+1,0);
        for(int j=0;j<n;j++){
            if((1<<j)&i){
                auto option = dp[(1<<j)^i]; //shallow copy
                if(option.second+arr[j]<=x){
                    option.second+=arr[j];
                }else{
                    option.first+=1;
                    option.second=arr[j];
                }
                dp[i] = min(dp[i],option);
            }
        }
    }

    cout<<dp[(1<<n)-1].first<<"\n";






    return 0;
}