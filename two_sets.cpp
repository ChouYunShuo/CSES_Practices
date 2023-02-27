#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 3)
        cout << "NO\n";
    else if (n == 3)
    {
        cout << "YES\n1\n3\n2\n2 1";
    }
    else
    {
        if (n % 4 == 0)
        {
            cout << "YES\n";
            cout << n / 2 << "\n";
            string cur;
            for (int i = 1; i <= n / 2; i++)
            {
                if (i == n / 4 + 1)
                {
                    cout << cur.substr(0, cur.size() - 1) << "\n";
                    cout << n / 2 << "\n";
                    cur = "";
                }
                cur += to_string(i) + ' ' + to_string(n - i + 1) + ' ';
            }
            cout << cur.substr(0, cur.size() - 1) << "\n";
        }
        else if (n % 4 == 3)
        {
            cout << "YES\n";
            cout << (n + 1) / 2 << "\n";
            string cur;
            for (int i = 1; i <= n / 2; i++)
            {
                if (i == (n + 1) / 4 + 1)
                {
                    cout << cur.substr(0, cur.size() - 1) << "\n";
                    cout << n / 2 << "\n";
                    cur = "";
                }
                cur += to_string(i) + ' ' + to_string(n - i) + ' ';
            }
            cout << cur + to_string(n) << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}