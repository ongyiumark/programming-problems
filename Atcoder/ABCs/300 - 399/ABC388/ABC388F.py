n, m, a, b = list(map(int, input().split()))
l, r = [0]*m, [0]*m
for i in range(m):
    l[i], r[i] = list(map(int, input().split()))


def solve():
    if a == b:
        if n % a != 1%a:
            return False
        
        for i in range(m):
            # smallest k such that 1+ka >= l[i]
            k = (l[i]-1+a-1)//a
            if 1+k*a <= r[i]:
                return False
        return True
    
    # assume a < b
    is_reachable = [None]*(b*(b-1))
    is_reachable[0] = True
    def reachable(w):
        """Checks if a combination of (a, a+1, ..., b) can add to w."""
        if b*(b-1) <= w:
            return True
        
        if is_reachable[w] is not None:
            return is_reachable[w]

        for i in range(a, min(b,w)+1):
            if reachable(w-i):
                is_reachable[w] = True
                return is_reachable[w]
        
        is_reachable[w] = False
        return is_reachable[w]

    s, t = [0]*(m+1), [0]*(m+1)
    s[0] = 1
    t[m] = n
    for i in range(m):
        s[i+1] = r[i]+1
        t[i] = l[i]-1
    
    valid = dict()
    valid[1] = True
    for i in range(m+1):
        # calculate validity of (s[i], ..., s[i]+b-1)
        for start in range(s[i], min(s[i]+b-1, t[i])+1):
            for move in range(a, b+1):
                if valid.get(start-move, False):
                    valid[start] = True
        
        # calculate validity of (t[i]-b+1, ..., t[i])
        for start in range(s[i], min(s[i]+b-1, t[i])+1):
            if not valid.get(start, False):
                continue
            for end in range(max(t[i]-b+1, s[i]), t[i]+1):
                if start > end:
                    continue
                if reachable(end-start):
                    valid[end] = True

    return valid.get(n, False)

print("Yes" if solve() else "No")

