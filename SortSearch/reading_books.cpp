#include <iostream>
#include <vector>
using namespace std;
#define ll long long


int main(){
    int n;
    cin>>n;
    vector<ll> arr(n);
    ll sum = 0, mx=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        mx=max(mx, arr[i]);
    }
    if(2*mx>sum) cout<<2*mx<<'\n';
    else cout<<sum<<"\n";


    return 0;
}

//5 1 5 5 1 3 4 5 1 4