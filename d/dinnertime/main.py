n=int(input())
insts=[input().split() for _ in range(n)]

ans = 1
p = 0
g = 0
for t, k in insts:
    k = int(k)

    if t == "G":
        if p >= g:
            ans += min(p - g, k)
        g += k
    else:
        if p < g <= p + k:
            ans += 1
        p += k

print(ans)
