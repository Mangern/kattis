n=int(input())
if n <= 0:
    print(-abs(n)*(abs(n)+1)//2+1)
else:
    print(n*(n+1)//2)
