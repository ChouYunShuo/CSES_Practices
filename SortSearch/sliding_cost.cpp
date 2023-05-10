#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const int mxN = 2e5;
int arr[mxN];

int main(){
    int n,k;
    cin>>n>>k;
    multiset<int> lo;
    multiset<int> hi;
    
    long long lo_sum=0, hi_sum=0;

    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> init(arr, arr+k);
    sort(init.begin(),init.end());
    for(int i=0;i<k-k/2;i++){
        lo.insert(init[i]);
        lo_sum+=init[i];
    }
    for(int i=k-k/2;i<k;i++){
        hi.insert(init[i]);
        hi_sum+=init[i];
    }

    if(k%2==1){
        ll mid = *lo.rbegin();
        cout<<mid*lo.size()-lo_sum+hi_sum-mid*hi.size()<<" ";
    }else{
        double mid = (*lo.rbegin()+*hi.begin())/2;
        cout<<ll(mid*lo.size()-lo_sum+hi_sum-mid*hi.size())<<" ";
    }
    for(int i=k;i<n;i++){
        if(lo.find(arr[i-k])!=lo.end()){
            lo_sum-=arr[i-k];
            lo.erase(lo.lower_bound(arr[i-k]));
        }else{
            hi_sum-=arr[i-k];
            hi.erase(hi.lower_bound(arr[i-k]));
            ll cur = *lo.rbegin();
            hi.insert(cur);
            lo.erase(lo.lower_bound(cur));
            hi_sum+=cur;
            lo_sum-=cur;
        }

        hi.insert(arr[i]);
        hi_sum+=arr[i];
        if (hi.size()>lo.size()) {
            ll cur = *hi.begin();
            lo.insert(cur);
            hi.erase(hi.begin());
            lo_sum+=cur;
            hi_sum-=cur;
        }

        if(k%2==1){
            ll mid = *lo.rbegin();
            cout<<mid*lo.size()-lo_sum+hi_sum-mid*hi.size()<<" ";
        }else{
            double mid = (*lo.rbegin()+*hi.begin())/2;
            cout<<ll(mid*lo.size()-lo_sum+hi_sum-mid*hi.size())<<" ";
        }
    }

    return 0;
}