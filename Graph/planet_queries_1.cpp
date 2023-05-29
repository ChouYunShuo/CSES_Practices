#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MAXN = 2e5 + 5;
const int MAXD = 30;  // ceil(log2(10^9))
int n,q;
int succ_k[MAXD][MAXN];
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>q;
   
    for(int i=1;i<=n;i++){
        cin>>succ_k[0][i];
    }
    
    for(int i=1;i<MAXD;i++){
        for(int j=1;j<=n;j++){
            succ_k[i][j] = succ_k[i-1][succ_k[i-1][j]];
        }
    }

    for(int i=0;i<q;i++){
        int x,k;
        cin>>x>>k;
        for(int j=MAXD-1;j>=0;j--){
            if(k&(1<<j)) x=succ_k[j][x];
        }
        cout<<x<<"\n";
    }
    return 0;
}