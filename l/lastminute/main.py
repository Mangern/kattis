au,bu,ar,br = map(int,input().split())

ans = ar * br

if br > 0 and ar > 0:
    ans += au + bu
elif br > 0:
    ans += au
elif ar > 0:
    ans += bu
else:
    ans += min(au,bu)
print(ans)
