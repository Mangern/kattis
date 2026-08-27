x,y=map(float,input().split())
n = int(input())

shield = []

for i in range(n):
    l,u,f = map(float,input().split())
    shield.append((l,u,f))

shield.sort()

sm = 0.0
prv = 0.0

for l,u,f in shield:
    sm += l - prv
    sm += f * (u - l)
    prv = u

sm += y - prv

print(x / sm)

