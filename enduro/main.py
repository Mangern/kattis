def parsetime(s):
    t,v=s.split()
    hr,mn,sc=t.split(":")
    hr = int(hr) % 12 + (12 if v == "PM" else 0)
    mn = int(mn)
    sc = int(sc)
    return hr * 3600 + mn * 60 + sc

st = parsetime(input())
n=int(input())
ended=set()
cnt={}
ans=[]
for _ in range(n):
    line=input()
    t=parsetime(line[:11])
    t = (t - st) % (24 * 60 * 60)
    name=line[12:]
    if t < 3 * 3600:
        if name not in cnt:
            cnt[name] = 0
        cnt[name] += 1
    elif name not in ended:
        if name not in cnt:
            cnt[name] = 0
        cnt[name] += 1
        ans.append((cnt[name], -t, name))
        ended.add(name)
ans.sort(reverse=True)
for a,b,c in ans:
    print(a, c)
