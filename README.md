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
