2021-2022 ACM-ICPC Brazil Subregional Programming Contest

Problem N - No Luck
    - Uses merge sort segment tree
        - segment tree where the nodes are sorted vectors
        - parent two nodes are the merged sort the two vectors
    - Can answer query of how many [l,r] are >= x.

Problem C - Creating Multiples
    - Uses euler's theorem for modular inverse
    - Uses sieve for multiplicative function (totient)
        - This wasn't required for this problem since the constraints weren't too strict
        - Manually computing the totient was sufficient

Problem M - Monarchy in Vertigo
    - No special algorithm required (standard dfs)
    - The idea was just to build the entire tree first, find the order of succession, then print answer the queries.

Problem G - Getting in Shape
    - Look for the pattern by implementing a checker.
    - Looks like strings of contiguous A's represent a fibonacci number, and the number of ways is multiplied when they are separated with a B.
    - We simply need to find a way to decompose N into a product of fibonacci numbers.
        - Recursive backtracking works
    - Smart solution is dp where pos(n, i) is true if its possible to decompose n with numbers of index <= i.
        - We can recover the solution by checking if n%f[i] == 0 and pos(n/f[i], i) is true.