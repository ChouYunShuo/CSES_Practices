#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n, 0);

    ll sum = 0;
    ll ans = LLONG_MAX;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());

    int cnt = 1;
    ll prefix = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            ll suffix = sum - cnt * arr[i - 1] - prefix;
            ans = min(ans, arr[i - 1] * (2 * i - cnt - n) - prefix + suffix);
            prefix += arr[i - 1] * cnt;
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    ans = min(ans, arr[n - 1] * (n - cnt) - prefix);
    cout << ans << "\n";
    return 0;
}

// 1 2 2 3 5
// 1 3 5 8
// 3*0-3+9
// #include <bits/stdc++.h>

// using namespace std;

// // variables used for the current problem
// int n, median;
// vector<int> p;
// long long ans, cnt;

// void solve() {
// 	cin >> n;
// 	p.resize(n);
// 	for (int &x : p) { cin >> x; }
// 	sort(p.begin(), p.end());
// 	median = p[n / 2];
// 	for (const int &x : p) {
// 		ans += abs(median - x);  // Calculate the cost to modify the stick
// 		                         // length
// 	}
// 	cout << ans << "\n";
// 	return;
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(nullptr);
// 	solve();
// 	return 0;
//}