###  Little Elephant and Candies

for i in range(int(input())):
    n, c = list(map(int, input().split()))
    ans = 0
    l = input().split()
    for i in range(n):
        ans += int(l[i])
        
    if ans <= c:
        print("Yes")
    else:
        print("No")

'''Input:
2
2 3
1 1
3 7
4 2 2

Output:
Yes
No'''