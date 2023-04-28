#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int dir_arr[5] = {1, 0, -1, 0, 1};
int p[48];
bool visited[9][9];
int dfs(int x, int y, int cur_len)
{
    // optimization: stop if there is a split

    if ((visited[x][y - 1] && visited[x][y + 1]) &&
        (!visited[x - 1][y] && !visited[x + 1][y]))
        return 0;
    if ((visited[x - 1][y] && visited[x + 1][y]) &&
        (!visited[x][y - 1] && !visited[x][y + 1]))
        return 0;
    if (x == 7 && y == 1)
    {
        if (cur_len == 48)
        {
            return 1;
        }
        return 0;
    }
    if (cur_len == 48) return 0;

    int ret = 0;
    //cout<<x<<" "<<y<<"\n";
    visited[x][y] = true;
    if (p[cur_len]<4){
        int cur_x = x + dir_arr[p[cur_len]];
        int cur_y = y + dir_arr[p[cur_len] + 1];
        if (!visited[cur_x][cur_y]) ret +=dfs(cur_x, cur_y, cur_len+1);
    }else{
        for (int i = 0; i < 4; i++)
        {
            int cur_x = x + dir_arr[i];
            int cur_y = y + dir_arr[i + 1];
            if (!visited[cur_x][cur_y]) ret += dfs(cur_x, cur_y,cur_len+1);

        }
    }
    
    visited[x][y] = false;
    return ret;
}
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < 9; i++) {
		visited[0][i] = true;
		visited[8][i] = true;
		visited[i][0] = true;
		visited[i][8] = true;
	}
    for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) { visited[i][j] = false; }
	}
    for(int i=0;i<48;i++){
        char cur = s[i];
        if (cur == 'D') p[i] = 0;
		else if (cur == 'L') p[i] = 1;
		else if (cur == 'U') p[i] = 2;
		else if (cur == 'R') p[i] = 3;
		else p[i] = 4;  // cur == '?'
    }

    int cur_len = 0;
    int startR = 1;
	int startC = 1; 

    int ans = dfs(startC, startR, cur_len);
    cout << ans << "\n";

    return 0;
}

/*

algorithm:

call dfs with initialization dfs(0,0, visited, s, 0)

dfs func:
check if visited all the squares; if yes ans+=1;
else{
    try to visit all the neighboring squares
    if (!visited and valid) dfs()
}
*/