#include <iostream>

using namespace std;

int n, k;

int main()
{
    // cin >> n >> k;
    // set<int> arr;
    // int p = k % n;
    // for (int i = 0; i < n; i++)
    // {
    //     arr.insert(i + 1);
    // }
    // while (arr.size())
    // {
    //     auto it = *arr.find_by_order(p);
    // }

    return 0;
}
// use linked lisk will TLE for large k;
//  class Node
//  {
//  public:
//      int value;
//      Node *next;

//     Node()
//     {
//         this->value = 0;
//         this->next = nullptr;
//     }

//     Node(int val)
//     {
//         this->value = val;
//         this->next = nullptr;
//     }
// };

// int main()
// {
//     cin >> n >> k;
//     Node *head = new Node(1);
//     Node *current = head;
//     for (int i = 2; i <= n; i++)
//     {
//         Node *cur = new Node(i);
//         current->next = cur;
//         current = cur;
//     }
//     current->next = head;

//     int cnt = 0;

//     while (cnt < n - 1)
//     {
//         for (int i = 0; i < k; i++)
//             current = current->next;

//         cout << current->next->value << " ";
//         Node *removed = current->next;
//         current->next = removed->next;
//         delete removed;
//         cnt++;
//     }
//     cout << current->value << "\n";
//     delete current;

//     return 0;
// }