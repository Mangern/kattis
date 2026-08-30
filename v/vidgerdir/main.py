n,m=map(int,input().split())
part_cnt={}
for _ in range(n):
    items=input().split(",")
    for it in items:
        name, err = it.split()
        if name not in part_cnt:
            part_cnt[name] = 0
        if int(err) == 0:
            part_cnt[name] += 1

print(min(part_cnt.values()))
