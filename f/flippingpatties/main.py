n = int(input())
dt = [tuple(map(int,input().split())) for _ in range(n)]

mt = max(dt, key=lambda t: t[1])[1]
arr = [0 for i in range(mt+1)]

for d,t in dt:
    arr[t] += 1
    arr[t-d] += 1
    arr[t-2*d] += 1

print((max(arr)+1)//2)
