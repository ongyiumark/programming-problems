import sys
input = lambda : sys.stdin.readline().strip()
sys.setrecursionlimit(2*10**5 + 5)

n, q = list(map(int, input().split()))
adj_list = [[] for _ in range(n)]
for i in range(n-1):
    a, b = list(map(int, input().split()))
    a -= 1
    b -= 1
    adj_list[a].append(b)
    adj_list[b].append(a)

timein = [None]*n
timeout = [None]*n

stack = [0]
timer = 0
def dfs(u):
    global timer
    timein[u] = timer
    for v in adj_list[u]:
        if timein[v] is not None:
            continue
        timer += 1
        dfs(v)
    timeout[u] = timer
dfs(0)

counters = [0]*(n+1)
for _ in range(q):
    p, x = list(map(int, input().split()))
    p -= 1
    counters[timein[p]] += x
    counters[timeout[p]+1] -= x


for i in range(n):
    counters[i+1] += counters[i]

print(*[counters[timein[i]] for i in range(n)])