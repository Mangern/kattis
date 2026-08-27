m=int(input())
n=int(input())
s=input().split()
a = [list(map(int,input().split())) for _ in range(n)]
sm=[0]*m
for l in a:
    for j, x in enumerate(l):
        sm[j] += x
print(s[sm.index(max(sm))])
