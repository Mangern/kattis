n=int(input())
lists=[input().split() for _ in range(n)]
names=list(set(x for l in lists for x in l))
score={name: [0]*11 for name in names}
for l in lists:
    for i, name in enumerate(l):
        score[name][0] += 1
        score[name][i+1] += 1
names.sort(key=lambda name: score[name])
if len(names) >= 2 and tuple(score[names[-1]]) == tuple(score[names[-2]]):
    print("tie")
else:
    print(names[-1])
