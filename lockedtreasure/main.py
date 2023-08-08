for _ in range(int(input())):
    n,m=map(int,input().split())
    k = n - m + 1
    ans = 1
    for i in range(k):
        ans *= n - i
    for i in range(k):
        ans //= i+1
    print(ans)

