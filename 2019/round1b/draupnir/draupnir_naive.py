import sys
import numpy as np
import math

def solve(w):
    sols = []
    for i in range(6):
        print(i+1)
        sys.stdout.flush()
        sols.append(int(input()))
    sols = np.array(sols)

    A = np.zeros((6, 6))
    for i in range(6):
        for j in range(6):
            A[i][j] = pow(2, math.floor((i+1)/(j+1)))
    x = np.linalg.solve(A, sols)
    for var in x:
        print(int(round(var)), end=' ')
    print()
    sys.stdout.flush()   
    correct = int(input())

    if correct == -1:
        sys.exit(1)


t, w = map(int, input().split())
for _ in range(t):
  solve(w)