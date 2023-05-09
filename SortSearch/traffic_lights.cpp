#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int x, n;
int main()
{
    cin >> x >> n;
    multiset<int> arr;
    set<int> loc;
    loc.insert(0);
    loc.insert(x);
    arr.insert(x);

    for (int i = 0; i < n; i++)
    {
        int c = 0;
        cin >> c;
        auto it = loc.insert(c).first;
        auto prevv = prev(it);
        auto nextt = next(it);
        auto itt = arr.find(*nextt - *prevv);
        arr.erase(itt);
        arr.insert(c - *prevv);
        arr.insert(*nextt - c);

        cout << *arr.rbegin() << " ";
    }

    return 0;
}