#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll n, cnt_2 = 0, cnt_5 = 0;
    cin >> n;

    for (int i = 2; i <= n; i *= 2)

        cnt_2 += (n / i);

    for (int i = 5; i <= n; i *= 5)

        cnt_5 += (n / i);

    cout << min(cnt_2, cnt_5) << '\n';
    return 0;
}