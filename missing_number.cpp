#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    int cur;
    cin >> n;
    long long sum = n * (n + 1) / 2;
    for (int i = 1; i < n; i++)
    {
        cin >> cur;
        sum -= cur;
    }
    cout << sum << "\n";
    return 0;
}