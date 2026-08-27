from itertools import accumulate,chain

n = int(input())
a = list(map(int,input().split()))
p = list(chain([0], accumulate(a)))

S = sum(a)

if S % 3 != 0:
    print(-1)
    exit()

for i in range(n):
    if p[i+1]*3==S:
        break
else:
    print(-1)
    exit()

for j in range(i+1,n):
    if (p[j+1]-p[i+1])*3==S:
        break
else:
    print(-1)
    exit()

print(i+1,j+1)
