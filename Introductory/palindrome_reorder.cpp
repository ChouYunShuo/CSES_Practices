#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string seq;
    cin >> seq;
    string ans = "";
    unordered_map<char, int> freq;
    for (char c : seq)
        freq[c]++;
    char mid_char = '\0';

    for (auto f : freq)
    {
        char c = f.first;
        int cur_freq = f.second;

        if (cur_freq % 2 == 1)
        {
            if (mid_char != '\0')
            {
                cout << "NO SOLUTION\n";
                return 0;
            }
            else
            {
                mid_char = c;
                ans = string(cur_freq / 2, c) + ans + string(cur_freq / 2, c);
            }
        }
        else
        {
            ans = string(cur_freq / 2, c) + ans + string(cur_freq / 2, c);
        }
    }

    if (mid_char != '\0')
        ans = ans.substr(0, ans.size() / 2) + mid_char + ans.substr(ans.size() / 2);
    cout << ans << '\n';
    return 0;
}
