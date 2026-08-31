# 0 0 2 0 0 0 1
# 1 2 2 3 3 2 1

# 0 0 0 0 0 0 2 0
# 1 2 3 4 4 3 2 3
# 
n=int(input())
a=list(map(int,input().split()))
mx_speed=[10**9]*n
mx_speed[n-1] = 10**9 if a[-1] == 0 else a[-1]
for i in range(n-2,-1,-1):
    if a[i] != 0:
        mx_speed[i] = min(mx_speed[i+1]+1, a[i])
    else:
        mx_speed[i] = mx_speed[i+1]+1

speed=0
ans=0
for i in range(n):
    speed = min(speed + 1, mx_speed[i])
    ans += 1 / speed
print(ans)
