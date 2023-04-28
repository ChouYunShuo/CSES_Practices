#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n;
    int c;
    int ans=1;
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>c;
        arr.push_back(c);
    }
    sort(arr.begin(), arr.end());
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]) ans++;
    }

    cout<<ans<<"\n";
    return 0;
}