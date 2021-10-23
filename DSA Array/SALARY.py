### The Minimum Number Of Moves  

import sys

input = sys.stdin.readline

def inp(): return(int(input()))
def lmis(): return(list(map(int,input().split())))
def mis(): return(map(int,input().split()))

for _ in range(inp()):
    n=inp()
    wrkr=lmis()
    wrkr.sort()
    print(sum(wrkr)-min(wrkr)*n)

"""
Input:
2
3
1 2 3
2
42 42

Output:
3
0
"""