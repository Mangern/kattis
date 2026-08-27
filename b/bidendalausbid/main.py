def tomin(s):
    hr,mn=s.split(":")
    return int(hr)*60+int(mn)
m1 = tomin(input())
m2 = tomin(input())
print((m2 - m1) % (24 * 60))
