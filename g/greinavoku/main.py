from math import ceil
cnt=0
cnt_woke=0
for _ in range(int(input())):
    for w in input().split():
        parts=len(w.split("-"))
        if parts > 2:
            cnt_woke += 1
        cnt += 1
print(f"Þessi texti er {int(ceil(cnt_woke/cnt*100))}% woke.")
