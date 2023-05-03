#include <iostream>
#include <map>
using namespace std;

const int mxN = 2e5;
int arr[mxN + 1], ans, cur;
map<int, int> sett;
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0, j = 0; i < n; i++)
    {
        j = max(sett[arr[i]], j);
        ans = max(ans, i - j + 1);
        sett[arr[i]] = i + 1;
    }

    cout << ans << endl;

    return 0;
}