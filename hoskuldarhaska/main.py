ans=[]
n=int(input())
ws=[[] for _ in range(n)]
for _ in range(n):
    toks=input().split()[1:]
    toks.sort()
    ws[_] = toks
cur=[]
def search(i):
    if i == n:
        ans.append(cur.copy())
        return
    for w in ws[i]:
        cur.append(w)
        search(i+1)
        cur.pop()
search(0)
print("\n".join(map(lambda x: " ".join(x), ans)))
