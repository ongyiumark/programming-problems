k, n, w = [int(x) for x in input().split()]
print(max(k*w*(w+1)//2-n,0))