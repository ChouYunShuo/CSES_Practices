#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (ll k = 1; k <= n; k++)
    {
        ll sum = 0, attack = 0;
        sum = (ll)(k * k * (k * k - 1)) / 2;

        if (k > 3)
        {
            attack = 2 * 2 + 3 * 4 + (k - 4) * 4 * 2 + 4 * 2 + 6 * 2 * (k - 4) + (k - 4) * (k - 4) * 4;
            cout << sum - attack << "\n";
        }
        else
        {
            if (k == 3)
                cout << sum - 8 << "\n";
            else
                cout << sum << "\n";
        }
    }
    return 0;
}
