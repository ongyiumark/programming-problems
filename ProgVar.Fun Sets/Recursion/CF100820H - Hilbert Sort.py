n, S = [int(x) for x in input().split()]

places = []
for _ in range(n):
    x, y, s = input().split()
    x = int(x)
    y = int(y)
    places.append((x,y,s))

def hilbert_sort(places):
    if len(places) == 0:
        return []
    if len(places) == 1:
        return places
    
    sorted_places = []
    q1, q2, q3, q4 = [], [], [], []
    for x, y, s in places:
        if 2*x < S and 2*y < S: # first quadrant
            nx, ny = 2*x, 2*y # scale up
            nx, ny = ny, 2*S-nx # rotate clockwise
            nx, ny = nx, 2*S-ny # flip 
            q1.append((nx, ny, s))
        elif 2*x < S and 2*y > S: # second quadrant
            nx, ny = 2*x, 2*y # scale up
            nx, ny = nx, ny-S # shift down
            q2.append((nx, ny, s))
        elif 2*x > S and 2*y > S: # third quadrant
            nx, ny = 2*x, 2*y # scale up
            nx, ny = nx-S, ny-S # shift down and left
            q3.append((nx, ny, s))
        else: # fourth quadrant
            nx, ny = 2*x, 2*y # scale up
            nx, ny = 2*S-ny, nx # rotate counter-clockwise
            nx, ny = nx, 2*S-ny # flip 
            nx, ny = nx-S, ny # shift left
            q4.append((nx, ny, s))

    q1 = hilbert_sort(q1)
    q2 = hilbert_sort(q2)
    q3 = hilbert_sort(q3)
    q4 = hilbert_sort(q4)

    return q1+q2+q3+q4
    
result = hilbert_sort(places)
print('\n'.join([result[i][-1] for i in range(n)]))