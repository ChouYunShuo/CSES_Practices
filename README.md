# CSES Practices

A coding project for CSES Problem set in C++

## Introductory Problems

### 1. Weird Algorithm

### 2. Missing Number

### 3.Repetitions

### 4.Increasing Array

### 5.Permutations

### 6.Number Spiral

### 7.Two Knights

### 8.Two Sets

### 9.Bit Strings

### 10.Trailing Zeros

### 11.Coin Piles

### 12.Palindrome Reorder

### 13.Gray Code

### 14.Tower of Hanoi

Recursion:

- Move the top n-1 disks from the left stack to the middle stack using the right stack as an auxiliary.
- Move the largest disk from the left stack to the right stack.
- Move the n-1 disks from the middle stack to the right stack using the left stack as an auxiliary.

### 15.Creating Strings

Recursion:

- Recursive construct all strings with length (n-1)
- add current char in the front, and use a unordered_set to avoid duplication

### 16.Apple Division

Recursion:

- Find all subset sum
- use bit maniputation or backtrack to find the subsets

### 17.Chessboard and Queens

Backtrack

- Classic backtrack problem
- Don't make mistakes on checking if 2 queens collide (need abs)

### 18.Digit Queries

### 19. Grid Paths

- Use global array is faster than parsing vector as params in recursion
- prune the tree
- use an additional array to store current direction(input)

## Sort and Search Problems

### 1. Distinct number

- sort with one pointer scan

### 3. Ferris Wheel

- sort with two pointer scan

### 5. Restaurant Customers

- prefix sum, while for every time customer +1 when entry, -1 when exit

### 7. Sum of Two Values

- maintain a set(not unordered_set), and check if target-arr[i] is in the set. Get index using set.find()

### 9. Stick Lengths

- find the medium(observe!!) and get abs() for all the rest

### 11. Collecting Numbers

- create an index array and return the number of decreasing pairs.

### 13. Playlist

- use a map to keep track of current char's previous index. Maintain a pointer j, that is the current start of the window. j = max(j, set[arr[i]])

### 15. Traffic Light

- use a multiset and set, the set keeps all the current traffic light locations and the multiset keeps all the current passage without traffic lights(may have multiple with same lengths). For each iteration, insert the current traffic light and update the passage lengths, should remove one and add two new. Print the longest one. Use std::prev, std::next. 

### 17. 

### 19. Nested range count

### 21. Factory Machines

- binary search, with lo=0, hi=1e18, s+=min(mid/arr[i], (ll)1e9); need to check if overflow

### 23. Reading Books

- The first person read the longest time book, check if 2*longest>sum.

### 25. Sum of Four Values

- Save all the pairs sum(n choose two), and then loop over all i,j pairs and check if target-arr[i]-arr[j] exists

### 27. Subarray Sums 1

- Prefix sum. Use a set to see if target - current prefix exists in the set.

### 29. Subarray Divisibility

- Prefix sum. store all prefix sum that is i mod N, and (n chooses 2) for all pairs in i. If two prefix sum has the same mod, then that subarray is dividable by n.

### 31. Array division

- Binary search, with lo=0, hi=2e14. the mid value is current maximum value of the subarray, check if the array can be successfully divided using under this max value. Two conditions: 1. all array values smaller or equal to mid and 2. need grp less or equal to k to divide all numbers.


### 33. Sliding Cost

- Use two multiset to maintain the median of a sliding window, so the insert, delete operation can be done in O(k). Calculate the sliding window cost= mid*lo.size()-lo_sum+hi_sum-mid*hi.size(). Need to discuss even or odd.

### 35. Maximum Subarray Sum 2

- Use a prefix array with a multiset, multiset keeps all prefixes within [a,b]. iterate over max(ans, prefix[i]-*ms.begin()). 

## Dynamic Programming

### 1. Dice Combinations

- 1D DP, don't forget to use long long and use mode 1e9+7


### 3. Coin Combinations I

- simple 1D DP. DP array store combinations for current value.

### 5. Removing Digits

- simple 1D DP, DP array store minimum steps for current value. The subproblems are:  dp[i] = min(dp[i], dp[i-cur%10]);