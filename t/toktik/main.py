score={}
for _ in range(int(input())):
    s,n=input().split()
    n=int(n)
    if s not in score:
        score[s] = 0
    score[s] += n
print(max(score.items(), key=lambda t:t[1])[0])
