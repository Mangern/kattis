h,m=map(int,input().split())

while h >= 30:
    h -= 30

h_expect = m / 12
print("yes" if h == h_expect else "no")
