#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int maxN = 1e5;
int cc,maxx;
map<int,int> comp_size;
int p[maxN];


int find(int c){
    if(c==p[c]) return c;
    p[c] = find(p[c]);
    return p[c];
}
void merge(int a, int b){
    int pa = find(a), pb = find(b);
    if (pa==pb) return;
    
    
    if( comp_size[pa]> comp_size[pb]){
        p[pb] = pa;
        comp_size[pa]+=comp_size[pb];
        maxx = max(maxx, comp_size[pa]);
    }else{
        p[pa] = pb;
        comp_size[pb]+=comp_size[pa];
        maxx = max(maxx, comp_size[pb]);
    }
   
    cc--;
    
}
int main(){
    int n,m,a,b;
    vector<pair<int,int> >q;
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>m;
    cc = n;
    maxx = 1;

    for(int i=1;i<=n;i++){
        p[i] = i;
        comp_size[i] = 1;
    }

    for(int i=0;i<m;i++){
        cin>>a>>b;
        q.push_back(make_pair(a,b));
    }
    for(int i=0;i<m;i++){
        merge(q[i].first,q[i].second);
        cout<<cc<<" "<<maxx<<"\n";
    }
    return 0;
}