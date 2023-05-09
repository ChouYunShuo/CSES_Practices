#include <iostream>
using namespace std;

#define ll long long

const int mxN = 2e5;
int arr[mxN];
int main(){
    int n,t;
    cin>>n>>t;
    ll lo=0, hi=1e18;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    while(lo<hi){
        ll mid=(lo+hi)/2, s=0;
        for(int i=0;i<n;i++){
            s+=min(mid/arr[i], (ll)1e9);
        }
        if(s>=t) hi = mid;
        else lo=mid+1;
    }
    cout<<lo<<"\n";

    return 0;
}