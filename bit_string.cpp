#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= 2;
        ans %= 1000000007;
    }
    cout << ans;
    return 0;
}