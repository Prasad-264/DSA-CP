from math import ceil, log2, floor,sqrt,gcd
from collections import defaultdict,deque

import sys
import os.path

sys.setrecursionlimit(200000)
if (os.path.exists('input.txt')):
    sys.stdin = open("input.txt", "r+")
    sys.stdout = open("output.txt", "w")


# input = sys.stdin.readline
# print=sys.stdout.write
def MI():
    return map(int, input().split())

def bfs(s,adj):
     
    V = 10**5+2
    visited = [False] * V
    level = [0] * V
  
    for i in range(V):
        visited[i] = False
        level[i] = 0
    queue = deque()
    visited[s] = True
    queue.append(s)
    level[s] = 0
  
    while (len(queue) > 0):

        s = queue.popleft()
        for i in adj[s]:
            if (not visited[i]):
                level[i] = level[s] + 1
                visited[i] = True
                queue.append(i)
  

    
             
    return level

def dfs(node,tree,d,v,afv,val,parent,gcdo):
    v[node]=1
    # print(node)
    
    for j in d[node]:
        if v[j]==0:
            parent[j]=node
            tree[node].append(j)
            dfs(j,tree,d,v,afv,val,parent,gcdo)
            gcdo[node]=gcd(gcdo[j],gcdo[node])
            afv[node]+=gcdo[j]
            
