#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long num;
    cin >> num;
    while (num != 1)
    {
        cout << num << " ";
        if (num % 2 == 0)
            num /= 2;
        else
            num = num * 3 + 1;
    }
    cout << 1 << "\n";

    return 0;
}