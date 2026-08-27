def time_val(s):
    t,apm=s.split()
    h,m=map(int,t.split(":"))
    h %= 12
    if apm[0] == 'p':
        h += 12

    return h * 60 + m
while True:
    n = int(input())
    if not n:
        break
    times = [input() for i in range(n)]

    times.sort(key=time_val)
    print("\n".join(times))
    print()
