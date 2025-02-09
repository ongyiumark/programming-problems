N = int(input())

dices = list()
sizes = list()
for _ in range(N):
    K, *A = list(map(int, input().split()))
    A_dict = dict()
    for face in A:
        A_dict[face] = A_dict.get(face, 0) + 1
    
    dices.append(A_dict)
    sizes.append(K)


ans = 0
for i in range(N):
    for j in range(i+1, N):
        A = dices[i]
        B = dices[j]
        sz_a = sizes[i]
        sz_b = sizes[j]

        if sz_a > sz_b:
            A, B = B, A
            sz_a, sz_b = sz_b, sz_a

        prob = 0
        for face, freq in A.items():
            prob += freq/sz_a * B.get(face,0)/sz_b
            
        ans = max(prob, ans)

print(f"{ans:.16f}")
