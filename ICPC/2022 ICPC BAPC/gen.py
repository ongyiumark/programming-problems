import random as rand
import sys

rand.seed(sys.argv[1])

w = 10000
print(w, int(1e18))

print(*(rand.randint(1, 10) for x in range(w)))