MOD = 10**9+7

def first_set(l, r):
    if r < l:
        return 0
    l %= MOD
    r %= MOD

    res = r*r - (l-1)*(l-1)
    res %= MOD
    if res < 0:
        res += MOD

    return res

def second_set(l, r):
    if r < l:
        return 0
    l %= MOD
    r %= MOD

    res = r*(r+1) - (l-1)*l
    res %= MOD
    if res < 0:
        res += MOD
    return res

def solve(n):
    prev_1, curr_1 = 1, 1
    prev_2, curr_2 = 1, 1

    total = 0
    cnt = 1
    set_id = 0
    while n >= cnt:
        if set_id == 0:
            # first set
            curr_1 = prev_1 + cnt-1
            total += first_set(prev_1, curr_1)
            total %= MOD
            prev_1 = curr_1+1
        else:
            # second set
            curr_2 = prev_2 + cnt-1
            total += second_set(prev_2, curr_2)
            total %= MOD
            prev_2 = curr_2+1

        n -= cnt
        cnt *= 2
        set_id = 1-set_id
    
    if set_id == 0:
        total += first_set(prev_1, prev_1+n-1)
    else:
        total += second_set(prev_2, prev_2+n-1)
    total %= MOD


    return total

l, r = [int(x) for x in input().split()]
res = solve(r)-solve(l-1)
res %= MOD
if res < 0:
    res += MOD
print(res)
