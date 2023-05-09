#include <iostream>
using namespace std;
typedef long long ll;

const int mxN = 2e5;
int arr[mxN],n,k;

bool isDivided(ll val){
    ll grp = 1, sum=0;
    for(int i=0;i<n;i++){
        if (arr[i]>val) return false;
        if(sum+arr[i]>val){
            grp++;
            sum = arr[i];
        }else{
            sum += arr[i];
        }
    }
    return grp<=k;
}

int main(){
    cin>>n>>k;
    ll lo=0, hi=2e14;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    while(lo<hi){
        ll mid = (lo+hi)/2;
        if(isDivided(mid)) hi = mid;
        else lo = mid+1;
    }

    cout<<lo<<"\n";
    return 0;
}

