from heapq import heappop, heappush

N, K = [int(x) for x in input().split()]
A = sorted([int(x) for x in input().split()], reverse=True)
B = sorted([int(x) for x in input().split()], reverse=True)
C = sorted([int(x) for x in input().split()], reverse=True)

priority_queue = list()
inserted = set()
def push(i, j, k):
    if i < N and j < N and k < N and (i,j,k) not in inserted:
        value = A[i]*B[j] + B[j]*C[k] + C[k]*A[i]
        inserted.add((i,j,k))
        heappush(priority_queue, (-value, i, j, k))

push(0,0,0)
for _ in range(K):
    val, i, j, k = heappop(priority_queue)
    push(i+1, j, k)
    push(i, j+1, k)
    push(i, j, k+1)

print(-val)