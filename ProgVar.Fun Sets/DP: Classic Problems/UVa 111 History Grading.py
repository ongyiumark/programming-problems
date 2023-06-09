import sys

def score(ordering, student):
    correct = [0]*len(ordering)
    for i, x in enumerate(ordering):
        correct[x-1] = i
    
    student_answer = [0]*len(student)
    for i, x in enumerate(student):
        student_answer[x-1] = i

    inverse = {x:i for i,x in enumerate(correct)}
    ranks = [inverse[x] for x in student_answer]

    lis = []
    for x in ranks:
        sz = len(lis)
        if sz == 0 or lis[-1] < x:
            lis.append(x)
            continue
        
        lo = 0
        hi = sz-1
        ans = sz

        while lo <= hi:
            mid = hi - (hi-lo)//2
            if x < lis[mid]:
                ans = mid
                hi = mid-1
            else:
                lo = mid+1
        
        lis[ans] = x
        # print(lis)

    # print(ordering)
    # print(student)
    # print(ranks)
    # print(len(lis))
    
    return len(lis)


    


lines = sys.stdin.readlines()
sz = len(lines)
idx = 0

while idx < sz:
    n = int(lines[idx])
    idx += 1

    ordering = [int(x) for x in lines[idx].split()]
    idx += 1

    while idx < sz:
        student = [int(x) for x in lines[idx].split()]
        if len(student) != n:
            break

        print(score(ordering, student))
        idx += 1
