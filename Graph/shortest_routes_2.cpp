#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;
const ll mi = 1e15+7;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll> > graph(n + 1, vector<ll>(n + 1, mi));
    vector<pair<int,int> > qs(q);
    for (int i = 0; i <= n; i++) graph[i][i] = 0;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(graph[a][b]>c){
            graph[a][b] = c;
            graph[b][a] = c;    
        }
    }

    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    for (int i = 0; i < q; i++) cin >>  qs[i].first >>  qs[i].second;

    for (int i = 0; i < q; i++){
        int x = qs[i].first, y=qs[i].second;
        if (graph[x][y] == mi) cout << -1 << "\n";
        else cout << graph[x][y] << "\n";
    }
    

    return 0;
}