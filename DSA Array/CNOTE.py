# Chef and Notebooks 
ans = ["LuckyChef","UnluckyChef"]
for z in range(int(input())):
    x, y, k, n = map(int, input().split())
    a = []
    q = x -y
    for _ in range(n):
        a.append(list(map(int, input().split())))
    for i in a:
        if i[0] >= q and i[1] <= k:
           print(ans[0])
           break
    else:
        print(ans[1])

"""
Input
3
3 1 2 2
3 4
2 2    
3 1 2 2
2 3
2 3    
3 1 2 2
1 1
1 2

Output
LuckyChef
UnluckyChef
UnluckyChef
"""