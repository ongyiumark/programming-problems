arr = []

N = int(input())
for i in range(2*N):
    user, time = list(input().split())
    time = int(time)
    arr.append((user,time))

arr.sort()
for i in range(0,len(arr),2):
    total = arr[i+1][1] - arr[i][1]
    if total > 216000: print(f'{arr[i][0]} overworked their PR0xF!')
    else: print(f'{arr[i][0]} has reasonable work hours!')
    