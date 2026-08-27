ds,ys=map(int,input().split())
dm,ym=map(int,input().split())

ans = 0

ps = ys - ds
pm = ym - dm

while True:
    m = min(ps,pm)
    ps -= m
    pm -= m
    ans += m

    if ps == 0 and pm == 0:
        break
    if ps == 0:
        ps = ys
    elif pm == 0:
        pm = ym
print(ans)
