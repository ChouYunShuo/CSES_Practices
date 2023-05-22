#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;

    vector<vector<char> > floor(r, vector<char>(c,'*'));
    vector<vector<int> > next(r, vector<int>(c,-1));
    vector<char> ans;
    int dir[] = {1,0,-1,0,1};
    char go[] = {'D', 'L', 'U', 'R'};
    queue<pair<int,int> > q;
    int sr=0,sc=0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char c;
            cin >> ws >> c;
            floor[i][j] = c;
            if(c=='M') q.push(make_pair(i,j));
            if(c=='A') {
                sr=i;sc=j;
            }
        }
    }
    
    q.push(make_pair(sr,sc));
    while(!q.empty()){
        auto cur = q.front();q.pop();
        
        int cr=cur.first, cc=cur.second;
        // cout<<cr<<" "<<cc<<"\n";
        if(floor[cr][cc]=='A' &&(cr==0||cr==r-1||cc==0||cc==c-1)){
            cout<<"YES\n";
            int dr=cr,dc=cc;
            int d=next[dr][dc];
            while(d!=-1){
                ans.push_back(go[d]);
                dr-=dir[d];dc-=dir[d+1];
                d=next[dr][dc];
            }
            cout<<ans.size()<<"\n";
            reverse(ans.begin(),ans.end());
            for(auto c:ans) cout<<c;
            return 0;
        }else{
            for(int i=0;i<4;i++){
                int nr=cr+dir[i], nc=cc+dir[i+1];
                if(nr>=0 && nr<r && nc>=0 && nc<c && floor[nr][nc]=='.'){
                    q.push(make_pair(nr,nc));
                    floor[nr][nc]=floor[cr][cc];
                    if(floor[nr][nc]=='A') {
                        next[nr][nc]=i;
                    }
                }
            }
        }
    }

    cout<<"NO\n";

    return 0;
}