n,k=map(int,input().split())
if n <= k:
    print(n)
    exit()
cnt = (n+k-1)//k
print(n//cnt)
