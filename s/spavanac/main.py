h,m=map(int,input().split())
t = h*60+m
t -= 45
if t < 0:
    t += 24*60

h = t//60
m = t%60
print(f"{h} {m}")
