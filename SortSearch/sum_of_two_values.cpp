#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
 
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    set<int> set;
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    for(int i=0;i<n;i++){
        if(set.find(x-nums[i])!=set.end()){
            int pos = find(nums.begin(), nums.end(), x-nums[i])-nums.begin();
            cout<<pos+1<<" "<<i+1<<"\n";
            return 0;
        }
        set.insert(nums[i]);
        
    }
    cout<<"IMPOSSIBLE\n";
 
    return 0;
}