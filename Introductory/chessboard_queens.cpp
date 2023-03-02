#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool check_collide(vector<pair<int,int> > cur_placements,int x, int y){
    for(auto p:cur_placements){
        if((p.first==x) || (p.second==y) || (y-p.second==x-p.first)){
            return true;
        }
    }
    return false;
}
void dfs(vector<string> board,vector<pair<int,int> >& cur_placements,int& ans){
    if(cur_placements.size()==8) {
        ans++;
        return;
    }
    for(int col=0;col<8;col++){
        int row = cur_placements.size();
        if(board[row][col]!='*' && !check_collide(cur_placements,col, row)){
            cur_placements.push_back(make_pair(col,row));
            dfs(board,cur_placements, ans);
            cur_placements.pop_back();
        }
    }
}
int main(){
    vector<string> board(8);
    vector<pair<int,int> > cur_placements;
    int ans=0;
    for(int i=0;i<8;i++) cin>>board[i];
    dfs(board, cur_placements,ans);
    cout<<ans<<"\n";
    return 0;
}