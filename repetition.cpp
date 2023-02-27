#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string seq;
    int cur = 1, ans = 1;
    cin >> seq;
    for (int i = 1; i < seq.length(); i++)
    {
        if (seq[i] == seq[i - 1])
            cur++;
        else
        {
            ans = max(ans, cur);
            cur = 1;
        }
    }
    ans = max(ans, cur);
    cout << ans << '\n';
    return 0;
}