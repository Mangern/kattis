n,c=map(int,input().split())
t_s=0
for _ in range(n):
    m,s=map(int,input().split(":"))
    t_s += m * 60 + s
t_s -= c * (n - 1)
h = t_s // 3600
t_s -= h * 3600
m = t_s // 60
t_s -= m * 60
print(f"{h:02d}:{m:02d}:{t_s:02d}")
