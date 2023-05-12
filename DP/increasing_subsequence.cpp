#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    vector<int> dp;
    
    for(int i=0;i<n;i++) cin>>arr[i];

    dp.push_back(0);
    dp.push_back(arr[0]);
    
    for(int i=1;i<n;i++){
        auto it = lower_bound(dp.begin(), dp.end(),arr[i]);
        if(it==dp.end()){
            dp.push_back(arr[i]);
        }else{
            int pos = it-dp.begin();
            dp[pos] = arr[i];
        }
    }

    cout<<dp.size()-1<<"\n";




    return 0;
}