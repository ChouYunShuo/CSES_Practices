#include <iostream>

using namespace std;

typedef long long ll;

const int mxN = 2e5;
ll arr[mxN];

int main(){
    int n;
    ll ans=0, ps =0;
    cin>>n;
    arr[ps] = 1;

    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        ps+=x;
        arr[(ps%n+n)%n]+=1; // need to deal with negatives, turn to same mod (N) in the positive
    }

    for (auto i:arr){
        ans+= i*(i-1)/2;
    }
    cout<<ans<<"\n";

    int aa[5]={0};
    cout<<sizeof(arr[0]);
    return 0;
}