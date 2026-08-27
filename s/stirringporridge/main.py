T=int(input())
tot=0
cur=1
ans=0
while True:
    if tot + cur <= T:
        tot += cur
        cur += 1
    else:
        break
print(cur-1)
