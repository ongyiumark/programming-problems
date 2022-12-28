Solved ABC148 E - Double factorial, ABC195 - Coprime Present, and ABC208 - Digit Products

For double factorial, I just expressed the double factorial in terms of normal factorials and used Legendre's formula.

I solved both coprime present and digit products pretty quickly. Around 30 mins each, but my solution for Digit products is sus.
For coprime presents, since `B-A+1 <= 73`, the largest gcd is `73`. So I just needed to keep track of all primes less than or equal to `73`.
Turns out there are only `21`. I just built an array from `A to B` which would be at most size `73`.
Then `dp[i][mask]` where `i` is the current index and `mask` holds which primes (out of the 21) are already taken.
2D array would MLE, so I just used a `map`.

For Digit Products, I just did the naive digit dp, but with `map`. The state is `(i, j, lower, start)` where `i` is the index, `j` is the current product (which can go as high as `9**18`), `lower` is a flag if its already lower than `n`, and `start` is a flag for leading zeros. I just copiumed that we wouldn't visit that many products, and it worked. Idk if testcases are weak, but it ran in `303ms`. 

After giving it some more thought, we're just visiting numbers with the form `2**a, 3**b, 5**c, 7**d`, so I'm guessing its something like `O(log(n)**4)` times the log factor from the `BST`. But I didn't do this analysis when I solved it HAHAH.