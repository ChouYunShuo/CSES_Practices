#include <iostream>
#include <map>
#include <vector>

using namespace std;
#define ll long long 
int main(){
    int n;
    ll x;
    cin>>n>>x;

    vector<int> nums(n);
    multimap<int, pair<int,int > > idx_pair;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            idx_pair.insert(make_pair(nums[i]+nums[j],make_pair(i,j)));
        }
    }
    //for(auto i:idx_pair) cout<<i.first<<"\n";
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            auto lb = idx_pair.lower_bound(x-nums[i]-nums[j]);
            if(lb!=idx_pair.end()&&(*lb).first+nums[i]+nums[j]==x){
                if((*lb).second.first!=i&&(*lb).second.first!=j&&(*lb).second.second!=i&& (*lb).second.second!=j){
                    cout<<i+1<<" "<<j+1<<" "<<(*lb).second.first+1<<" "<<(*lb).second.second+1<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE\n";


    return 0;
}