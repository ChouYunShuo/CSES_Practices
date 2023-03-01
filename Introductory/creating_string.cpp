#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<string> dfs(string s, int len){
    vector<string> cur_ans;
    if (len==1) {
        cur_ans.push_back(s);
        return cur_ans;
    } 
    else{
        unordered_set<char> cset;
        for(int i=0;i<s.size();i++){
            if(cset.find(s[i])==cset.end()){
                cset.insert(s[i]);
                auto cur = dfs(s.substr(0,i)+s.substr(i+1), len-1);
               
                for (auto c:cur) {
                    cur_ans.push_back(s[i]+c);
                }
                
            }
        }
    }
    return cur_ans;
}
int main(){
    string s;
    vector<string> ans;
    cin>>s;
    sort(s.begin(),s.end());
    ans = dfs(s, s.size());
    cout<<ans.size()<<'\n';
    for(auto c:ans) cout<<c<<"\n";

    return 0;

}