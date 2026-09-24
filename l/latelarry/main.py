s,md=input().split()
h,m=map(int,s.split(":"))
h %= 12
t=60*h+m
if md=="PM":
    t += 12*60
x=int(input())
t -= x
t %= (60 * 24)
md = "AM"
if t >= 12 * 60:
    md = "PM"
    t -= 12 * 60
h = t // 60
m = t % 60
if h == 0:
    h = 12
print(f"{h}:{m:02d} {md}")
