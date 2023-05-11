#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;

    vector<int> price_arr(n,0);
    vector<int> page_arr(n,0);

    vector<int> dp_prev(x+1,0);

    for(int i=0;i<n;i++) cin>>price_arr[i];
    for(int i=0;i<n;i++) cin>>page_arr[i];

    for(int i=0;i<n;i++){
        vector<int> dp_cur(x+1,0);
        for(int w=0;w<=x;w++){
            if(w==0) dp_cur[w] = 0;
            else {
                if(w-price_arr[i]>=0){
                    dp_cur[w] = max(dp_prev[w], dp_prev[w-price_arr[i]]+page_arr[i]);
                }else{
                    dp_cur[w] = dp_prev[w];
                }
            }
        }

        dp_prev = dp_cur;
    }

    cout<<dp_prev[x]<<"\n";


    return 0;
}