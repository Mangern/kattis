day=["Mon","Tue","Wed","Thu","Fri","Sat","Sun"]
def parse(s):
    d,rest=s.split()
    hr,mn=rest.split(":")
    return day.index(d) * 60 * 24 + int(hr)*60+int(mn)
start=parse(input())
end=parse(input())

diff = (end - start) % (60 * 24 * 7)
if diff == 0:
    print("7 days")
    exit()

d = diff // (60 * 24)
h = (diff // 60) % 24
m = diff % 60
ret=[]
if d>0:
    ret.append(f"{d} day{'s' if d>1 else ''}")
if h>0:
    ret.append(f"{h} hour{'s' if h>1 else ''}")
if m>0:
    ret.append(f"{m} minute{'s' if m>1 else ''}")
if len(ret) <= 2:
    print(" and ".join(ret))
else:
    print(", ".join(ret))
