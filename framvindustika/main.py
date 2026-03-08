p, w = map(int,input().split())

ans=["-"]*w

for i in range(1, w+1):
    if i / w <= p / 100:
        ans[i-1] = '#'

ans="".join(ans)
print(f"[{ans}] | {p:3d}%")
