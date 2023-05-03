#include <iostream>

using namespace std;

const int mxN = 2e5;
int n, arr[mxN], idx[mxN], ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        idx[arr[i] - 1] = i;
    }

    for (int i = 1; i < n; i++)
    {
        if (idx[i] < idx[i - 1])
            ans++;
    }
    cout << ans + 1 << "\n";

    return 0;
}