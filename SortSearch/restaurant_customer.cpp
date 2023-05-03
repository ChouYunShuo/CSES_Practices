#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int> > arr;
    vector<int> presum(2 * n, 1);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr.emplace_back(a, 1);
        arr.emplace_back(b, -1);
    }

    sort(arr.begin(), arr.end());
    for (int i = 1; i < 2 * n; i++)
    {
        presum[i] = presum[i - 1] + arr[i].second;
    }

    cout << *max_element(presum.begin(), presum.end()) << "\n";

    return 0;
}