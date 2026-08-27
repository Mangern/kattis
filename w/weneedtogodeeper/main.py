n=int(input())
ans=0
for w in range(2,22):
    for h in range(3,22):
        need=4+w*2+h*2
        if need<= n:
            ans += 1
print(ans)
