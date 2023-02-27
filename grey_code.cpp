#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<string> > all(n);
    all[0].push_back("0");
    all[0].push_back("1");
    
    for (int i = 1; i < n; i++)
    {
        int cnt = pow(2, i+1);
        for (int j = 0; j < cnt; j++)
        {
            if (j < cnt / 2)
            {
                all[i].push_back('0' + all[i - 1][j]);
            }
            else
            {
                all[i].push_back('1' + all[i - 1][cnt - j - 1]);
            }
        }
    }
    
    
    int cnt = pow(2, n);
    for (int i = 0; i < cnt; i++)
        cout << all[n - 1][i] << "\n";

    return 0;
}

/*
00 01 11 10 0 1 3 2

    000 001 011 010 110 111 101 100

    0 1 3 2 6 7 5 4
*/
