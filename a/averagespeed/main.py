from sys import stdin
def gett(st):
    h,m,s=map(int,st.split(":"))
    return (h * 3600 + m * 60 + s) / 3600
speed=0
dist=0
prev_t = 0
for line in stdin:
    parts=line.split()
    if len(parts) == 1:
        t = gett(parts[0])
        dt = t - prev_t
        prev_t = t

        dist += speed * dt
        print(f"{parts[0]} {dist:.2f} km")
    else:
        t = gett(parts[0])
        nspeed = int(parts[1])
        dt = t - prev_t

        dist += speed * dt

        speed = nspeed
        prev_t = t
