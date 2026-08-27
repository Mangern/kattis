n,s=map(int,input().split())
for _ in range(n):
    a,b=map(int,input().split())
    if a <= s <= b:
        s += 1
print(s)
