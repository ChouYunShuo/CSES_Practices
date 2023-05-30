#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxN=2e5+1;
int succ[maxN];
bool visited[maxN];
int ans[maxN];
queue<int> path;

void dfs(int &step, int cur){
    path.push(cur);
    step+=ans[cur]+1;
    if(visited[cur]){
        step--;
        return;
    }
    visited[cur] = true;
    
    dfs(step, succ[cur]);

}
int main(){
    int n;
    cin>>n;
    memset(visited,false,sizeof(visited));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<n;i++) cin>>succ[i+1];
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            queue<int> empty;
            swap(path, empty);
            int step = 0;
            dfs(step,i);
            int decrement = 1;
            int last =  path.back();
            // cout<<step<<"\n";
            while(!path.empty()){
                int cur = path.front();path.pop();
                // cout<<cur<<" ";
                if(cur ==last) decrement=0;
                ans[cur] = step;
                step-=decrement;
            }
        }
        // cout<<"\n";
    }

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";



    return 0;
}