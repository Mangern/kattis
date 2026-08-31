n=int(input())
cnt={}
for _ in range(n):
    a,b,c=input().split()
    if "(" in c:
        c = c[:c.find("(")]
    cnt[c] = cnt.get(c,0)+1
ans=list(cnt.items())
ans.sort()
for a,b in ans:
    print(a,b)
