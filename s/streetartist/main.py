ppl=[tuple(input().split()) for _ in range(int(input()))]

can = [False] * len(ppl)
can[-1] = True

prev = int(ppl[-1][1])
for i in range(len(ppl)-2, -1, -1):
    h = int(ppl[i][1])
    if h > prev:
        can[i] = True
        prev = h

ans=[]
for i in range(len(ppl)):
    if can[i]:
        ans.append(ppl[i][0])
print(" ".join(ans))
