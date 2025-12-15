n,m=map(int,input().split())
s=set(input().split())
for _ in range(n - 1):
    s &= set(input().split())
print(len(s))
for x in sorted(s):
    print(x)
