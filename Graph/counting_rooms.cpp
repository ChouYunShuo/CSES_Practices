#include <iostream>
#include <vector>

using namespace std;
int ans=0;

int dir[5] = {1,0,-1,0,1};
void dfs(int r, int c,vector<vector<char> >& floor, vector<vector<char> >& visited){
    visited[r][c] = true;

    for(int i=0;i<4;i++){
        int newr = r+dir[i]; 
        int newc = c+dir[i+1];
        if(newr>=0 && newc>=0 && newr<floor.size() && newc<floor[0].size() && !visited[newr][newc] && floor[newr][newc]=='.'){
            dfs(newr, newc, floor, visited);
        } 
    }
}
int main(){
    int r,c;
    cin>>r>>c;

    vector<vector<char> > floor(r, vector<char>(c,'*'));
    vector<vector<char> > visited(r, vector<char>(c,false));
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char c;
            cin >> ws >> c;
            floor[i][j] = c;
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(!visited[i][j] && floor[i][j]=='.') {
                dfs(i,j, floor, visited);
                ans++;
            }
        }
    }

    cout<<ans<<"\n";
    


    return  0;
}