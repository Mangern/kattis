from sys import stdin

for line in stdin:
    mo,d,y,lo,hi=line.split()
    t_lo = int(lo.split(":")[0])*60+int(lo.split(":")[1])
    t_hi = int(hi.split(":")[0])*60+int(hi.split(":")[1])
    d_t = t_hi - t_lo

    hr = d_t // 60
    mi = (d_t - 60*hr)
    print(f"{mo} {d} {y} {hr} hours {mi} minutes")
