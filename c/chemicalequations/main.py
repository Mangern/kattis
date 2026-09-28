recipe={}
n=int(input())
for _ in range(n):
    s,k=input().split()
    recipe[s] = []
    for i in range(int(k)):
        cnt,t=input().split()
        recipe[s].append((int(cnt), t))

goal=input()

dp={}

def make(s):
    global recipe
    global dp
    if s in dp:
        return dp[s]
    if s not in recipe:
        dp[s] = {s: 1}
        return dp[s]

    ret = {}
    for cnt, t in recipe[s]:
        sub = make(t)
        for k, v in sub.items():
            ret[k] = ret.get(k, 0) + v * cnt
    dp[s] = ret
    return dp[s]

for a,b in sorted(make(goal).items()):
    print(a,b)
