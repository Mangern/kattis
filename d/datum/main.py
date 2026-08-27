days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
md = [31,28,31,30,31,30,31,31,30,31,30,31]
dy = 3

gd,gm = map(int,input().split())

d = 1
m = 0

while d != gd or m+1 != gm:
    if d == md[m]:
        m += 1
        d = 1
    else:
        d += 1
    dy += 1

print(days[dy%7])

