k = int(input())

i = 0
lo = None
hi = None
while (1<<i) < k:
    if k & (1<<i):
        if lo is None:
            lo = i
        hi = i
    i += 1


ans = 0
if (1<<i) == k:
    ans = 0
else:
    ans = hi-lo+1

print(1<<i, ans)
