a,b=map(int,input().split())
n=int(input())
if a > b:
    a,b=b,a
l=set(int(input()) for _ in range(n))

if a == b:
    print(0)
    exit(0)
s = sum(10 for x in l if a < x < b)

print(4*(b-a)+s)
