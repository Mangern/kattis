r,b=map(int,input().split())

# r = 2*l+2*w-4
# l = 1/2(r - 2 * w + 4)

for l in range(1,r-1):
    w = r - 2 * l + 4
    if w & 1:
        continue
    w >>= 1
    if (w - 2) * (l - 2) == b:
        print(max(w,l),min(w,l))
        break
