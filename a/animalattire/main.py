# a1, a2, ... , ak
# a1 * a2 * ... * ak >= n
# minimize a1 + a2 + ... + ak

# for example if k == 4 and n == 30
# 2 * 2 * 3 * 3 == 36

k,n=map(int,input().split())

if k == 1:
    print(n)
    exit()

a=[1]*k

if k == 2:
    a[0] = max(1, int(n**0.5)-1)
    a[1] = max(1, int(n**0.5)-1)

def prod(a):
    r=a[0]
    for x in a[1:]:
        r *= x
    return r

while prod(a) < n:
    i = a.index(min(a))
    a[i] += 1
print(sum(a))
