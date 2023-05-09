#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const int mxN=2e5;
int tree[mxN];
int n;

int summ(int k){
    int s = 0;
    while(k>=1){
        s+=tree[k];
        k-= k&-k;
    }
    
    return s;
} 

void update(int k, int v){
    while (k<n){
        tree[k]+=v;
        k+=k&-k;
    }
}

int main()
{
    cin >> n;

    vector<pair<int,int> > ranges(n);
    map<int, int> idxmap;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        ranges[i] = make_pair(s, e);
        idxmap[e]=i;
    }
    int cnt=0;
   
    sort(ranges.begin(), ranges.end());

    for (int i = 0; i < n; i++)
    {
        update(idxmap[ranges[i].second],1);
    }
    for(auto it = idxmap.begin(); it != idxmap.end(); ++it){
        it->second = cnt;
        cnt++;
    }
    
   
    for (int i = 0; i < n; i++){
        cout<<summ(idxmap.size())-summ(idxmap[ranges[i].second])<<" ";
        //update(idxmap[ranges[i].second],-1);
    }
    
    return 0;
}