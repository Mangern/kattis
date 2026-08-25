bonus=[(0,0),(2000,25),(4000,50),(6000,75),(8000,150)]
c=int(input())

ans=0
for t1, b1 in bonus:
    for t2, b2 in bonus:
        if c >= t1:
            rem = c - t1
            if rem >= t2:
                ans = max(ans, b1 + b2)
print(ans)
