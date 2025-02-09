import sys
sys.setrecursionlimit(10**7)

n = int(input())
bitstring = input()


def solve(l, r):
    size = r-l+1
    if size == 1:
        return bitstring[l], 1

    # print(l, r)
    next_size = size//3

    result_1, num_1 = solve(l, l+next_size-1)
    result_2, num_2 = solve(l+next_size, l+next_size*2-1)
    result_3, num_3 = solve(l+next_size*2, r)
    
    result, num = None, None
    if result_1 == result_2 and result_2 == result_3:
        result = result_1
        num = min([num_1+num_2, num_1+num_3, num_2+num_3])
    elif result_1 == result_2:
        result = result_1
        num = min(num_1, num_2)
    elif result_1 == result_3:
        result = result_1
        num = min(num_1, num_3)
    else:
        result = result_2
        num = min(num_2, num_3)
    
    return result, num

result, num = solve(0, 3**n-1)
print(num)