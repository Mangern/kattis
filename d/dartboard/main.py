from math import exp
bi, bo, ti, to, di, do = map(float,input().split())
std = float(input())

def P(r):
    return 1 - exp(-(r*r)/(2*std*std))

ans = 50 * P(bi)
ans += 25 * (P(bo) - P(bi))

for i in range(1,21):
    ans += (P(ti) - P(bo))*i/20
    ans += (P(to) - P(ti))*i*3/20
    ans += (P(di) - P(to))*i/20
    ans += (P(do) - P(di))*i*2/20

print(ans)

