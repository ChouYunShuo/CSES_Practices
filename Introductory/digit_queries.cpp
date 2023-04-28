#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll xpow(ll x, unsigned int y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res *= x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll c = 1;
        ll p = 9;
        while (n > p)
        {
            // cout << p << endl;
            n -= p;
            c++;
            p = 9 * xpow(10, c - 1) * c;
        }
        n--;
        ll x = n / c;
        ll y = n % c;
        ll ans = xpow(10, c - 1) + x;
        // cout << ans << ' ' << x << ' ' << y << ' ' << n << ' ' << c << '\n';
        string s = to_string(ans);
        cout << s[y] << "\n";
    }

    return 0;
}
/*
1-9: 9
10-99: 90*2 10-189
100-999: 900*3 190-2889
1000-9999: 9000*4 2890-38889

*/
