# RECURSION

### Key Points

- Primary Goal: Take Decisions
- Secondary Goal: IP size reduces
- Choices + Decisions => Recursion possible

### Steps to solve

- Check if choices are available
- Build a recursion tree
- Code (cakewalk after recursion tree is built)

#### Example: Subset generation

Input
```
abc
```

Output
```
 , a, b, c, ab, bc, ac, abc
```
##### Decision Space

For each input character, we have 2 choices - accept or reject.

### Recursion Tree (IP - OP Method, Decisions are clear, for medium problems)

 - (OP,IP) => Representation of a node in a tree
 - #Branches = #Choices
 - Result obtained when IP = NULL
```
                             ("", ab)
                               /  \
                              /    \
                           (a,b)   ("",b)
                           /  \     /   \
                          /    \   /     \
                      (ab,)  (a,) (b,)  (,)                               
```

Subsets generated => {'', a, b, ab}

### Base - Hypothesis - Induction [IBH] (OP needed is clear, for easy problems)

- Base condition
    - Smallest valid input
- Used mostly in Tree and LL

Example: Print 1 to N / N to 1

 - Hypothesis:  go(7) - prints numbers from 1 to 7
                go(6) - prints numbers from 1 to 6

 - Induction:   go(n) --> go(n-1) --> go(n-2) --> ... --> Base cond
 - Base Cond:   if(n == 1) print(1);

### Applications

- Data Structures
    - Arrays, Strings
    - Linked List
    - Trees, Graphs
    - Heaps, Stack (Sometimes)
- Algorithms
    - DP
    - Backtracking
    - Divide & Conquer

### Problems Solved
- Easy
    - Print N to 1
    - Height of BT (TODO)
- Medium/Hard