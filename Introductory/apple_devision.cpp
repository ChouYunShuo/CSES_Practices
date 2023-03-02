#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
/*
void getSumSubset(vector<int> nums, vector<ll>& subsets){
    int len = nums.size();
    for(int i=0;i<(1<<len);i++){
        ll cur=0;
        for(int j=0;j<len;j++){
            if(i&(1<<j)) cur+=nums[j];
        }
        subsets.push_back(cur);
    }
    return ;
}*/
void getSumSubset(vector<int> nums, vector<ll>& subsets, ll& cur, int index){
    int len = nums.size();
    subsets.push_back(cur);
    for(int i=index;i<len;i++){
        cur += nums[i];
        getSumSubset(nums, subsets,cur, i+1);
        cur -= nums[i];
    }
}

int main(){
    int n;
    cin>>n;
    vector<ll> subsetsSum;
    vector<int> all(n);
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> all[i]; // read each integer and store it in the array
    }
    
    getSumSubset(all, subsetsSum, cur, 0);
    ll ans = INT_MAX;
    ll sum=0;
    for (auto v : all) sum += v;
    for(auto s:subsetsSum){
        ans = min(ans, abs(sum-2*s));
    }
    cout<<ans<<'\n';

    return 0;
}