p=[1,5,15,30,150]
idx=[0,1,2,3,4]
cnt=[0,0,0,0,0]
n=int(input())
while n > 0:
    while p[-1] > n:
        p.pop()
        idx.pop()
    n -= p[-1]
    cnt[idx[-1]] += 1
print(" ".join(map(str,cnt)))
