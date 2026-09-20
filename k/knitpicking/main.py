socks={}
for _ in range(int(input())):
    t,f,k=input().split()
    k=int(k)
    if t not in socks:
        socks[t] = {"left": 0, "right": 0, "any": 0}
    socks[t][f] = k


can = False
ans = 1
for t in socks:
    l = socks[t]["left"]
    r = socks[t]["right"]
    a = socks[t]["any"]

    ans += max(1, l, r)
    if l > 0 and (r + a > 0) or (r > 0 and (l + a > 0)) or a > 1:
        can = True

print(ans if can else "impossible")
