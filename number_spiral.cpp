#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        ll x, y, maxx, ans;
        cin >> x >> y;
        maxx = max(x, y);
        if (maxx % 2 == 0)
        {
            ans = 1 + maxx * (maxx - 1) + x - y;
        }
        else
        {
            ans = 1 + maxx * (maxx - 1) + y - x;
        }
        cout << ans << "\n";
    }

    return 0;
}