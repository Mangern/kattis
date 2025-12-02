n,k=map(int,input().split())
a=list(map(int,input().split()))
for x in a:
    if n - x < x - 1:
        print(n, end=" ")
    else:
        print(1, end=" ")
print()
