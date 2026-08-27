hrs = 0
mns = 0

dg = dict()

while True:
    mn_deg = (60*mns)
    hr_deg = (hrs * 60 + mns)*5

    deg = mn_deg - hr_deg


    if deg < 0:
        deg += 3600

    dg[deg] = (hrs,mns)

    if (hrs,mns) == (11,59):
        break
    mns += 1
    if mns == 60:
        mns = 0
        hrs += 1

n = int(input())
h,m=dg[n]
print(f"{h:0>2d}:{m:0>2d}")
