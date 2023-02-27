#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long len, ans = 0;
    cin >> len;
    vector<int> arr(len, 0);

    for (int i = 0; i < len; i++)
    {
        int cur;
        cin >> cur;
        arr[i] = cur;
    }

    for (int i = 1; i < len; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            ans += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }
    cout << ans << "\n";

    return 0;
}