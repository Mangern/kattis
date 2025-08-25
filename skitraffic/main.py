input()
h,m = map(int, input().split(":"))
t = h * 60 + m
if input() in ["sat", "sun"]:
    t *= 2
if int(input()) == 1:
    t *= 2
if int(input()) == 1:
    t *= 3
if int(input()) == 1:
    t *= 3
h = t // 60
m = t - h * 60
print(f"{h}:{m:02d}")
