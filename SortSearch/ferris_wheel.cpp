#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;

    vector<int> weights(n,0);
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }

    sort(weights.begin(),weights.end());
    int lp=0,rp=n-1;
    int ans = 0;

    while(lp<rp){
        if(weights[rp]+weights[lp]<=x) {
            rp--;
            lp++;
        }else{
            rp--;
        }
        ans++;
    }
    if(lp==rp) ans++;
    cout<<ans<<"\n";
    return 0;
}