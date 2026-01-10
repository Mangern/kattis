n=int(input())
ans=-1
tot=10**9
for i in range(n):
    s=input()
    w=0
    l=0
    for t, c in enumerate(s):
        if c == 'W':
            w += 1
        else:
            l += 1
            if l == 3:
                w = 0
                l = 0
        if w == 12 and t < tot:
            ans=i+1
            tot=t
print("INCOMPLETE" if ans == -1 else ans)
