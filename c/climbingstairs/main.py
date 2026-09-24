n,r,k=map(int,input().split())
if n % 2 != r % 2:
    n += 1
print(max(n,k+abs(k-r))+r)
