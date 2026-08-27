h,w,n=map(int,input().split())
a = map(int,input().split())

sm = 0
for x in a:
    if h == 0:
        break
    if sm + x == w:
        sm = 0
        h -= 1
    elif sm + x < w:
        sm += x
    else:
        break

print("YES" if h == 0 else "NO")
