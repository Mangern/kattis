n=int(input())
ans=[input() for _ in range(n)]
m=int(input())
stud=[(input(), [input() for _ in range(n)]) for _ in range(m)]
ids,scores=zip(*stud)
srt = input()
score = [sum(1 for a, b in zip(ans,std) if a==b) for std in scores]
res=list(zip(ids,score))
rev=srt.endswith("DESC")
if srt.startswith("STUDENT"):
    res.sort(key=lambda t: int(t[0]), reverse=srt.endswith("DESC"))
else:
    res.sort(key=lambda t: (t[1] * (-1 if srt.endswith("DESC") else 1), int(t[0])))
for a,b in res:
    print(a,b)
