def isp(n):
    s = f"{n:b}"
    return s[::-1]==s

def rev(x):
    res = 0
    while x:
        res = (res<<1) | (x & 1)
        x >>= 1
    return res

pal = {0, 1}

ln = 2
while len(pal) < 50000:
    mid = (ln>>1)
    for mask in range(1<<mid):
        if not ((mask >> (mid-1)) & 1):
            continue
        if ln % 2 == 1:
            for z in range(2):
                n = (mask << (mid+1))
                n |= (z << mid)
                n |= rev(mask)
                pal.add(n)
        else:
            n = (mask << mid)
            n |= rev(mask)
            pal.add(n)
    ln += 1

pal = sorted(pal)
m = int(input())
print(pal[m])
