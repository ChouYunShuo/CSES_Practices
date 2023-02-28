#include <iostream>
#include <vector>
using namespace std;

void towerOfHanoi(int n, char l, char m, char r, vector<string>& ans){
    if (n==1) {
        ans.push_back(std::string() +l+' '+r);
        return;
    }
    towerOfHanoi(n-1,l,r,m,ans);
    ans.push_back(std::string() +l+' '+r);
    towerOfHanoi(n-1,m,l,r,ans);
}
int main(){
    int n;
    cin>>n;
    vector<string>ans;

    towerOfHanoi(n,'1','2','3',ans);
    cout<<ans.size()<<'\n';

    for(auto move: ans){
        cout<<move<<'\n';
    }
    return 0;
}
/*
int main(){

    int n;
    cin>>n;
    vector<vector<string> > all(n);
    
    all[0].push_back("1 3");

    for(int i=1;i<n;i++){
        for(auto move: all[i-1]){
            string cur_move="";
            for(char c: move){
                if(c=='3') cur_move+='2';
                else if(c=='2') cur_move+='3';
                else cur_move+=c;
            }
            all[i].push_back(cur_move);
        }
        all[i].push_back("1 3");
        for(auto move: all[i-1]){
            string cur_move="";
            for(char c: move){
                if(c=='2') cur_move+='1';
                else if(c=='1') cur_move+='2';
                else cur_move+=c;
            }
            all[i].push_back(cur_move);
        }
    }
    cout<<all[n-1].size()<<'\n';

    for(auto move: all[n-1]){
        cout<<move<<'\n';
    }
    return 0;
}
*/


