n = int(input())
s = input()

indices = list()
for i in range(n):
    if s[i] == "1":
        indices.append(i)

num_ones = len(indices)

def solve():
    if num_ones == 1:
        return 0

    best_cost = float("inf")
    for center in ((num_ones-1)//2, num_ones//2):
        cost = 0
        count_left = center
        count_right = num_ones-center-1

        # process left
        for i in range(center):
            d = indices[center]-(count_left-i)-indices[i]
            cost += d
        
        for i in range(center+1, num_ones):
            d = indices[i]-(indices[center]+(i-center))
            cost += d

        best_cost = min(best_cost, cost)

    return best_cost
print(solve())