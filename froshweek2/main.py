n,m=map(int,input().split())
t = list(map(int,input().split()))
l = list(map(int,input().split()))
t.sort()
l.sort()
while len(t) and len(l):
    if t[-1] <= l[-1]:
        l.pop()
    t.pop()

print(m-len(l))
