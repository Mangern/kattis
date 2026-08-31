n=int(input())
a=input().split()
ans=a[n//2:]+a[:n//2]
print(' '.join(ans))
