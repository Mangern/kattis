n,q=map(int,input().split())
mp={}
for _ in range(n):
    a,b=input().split()
    it=a[0]+b[0]
    if it not in mp:
        mp[it] = []
    mp[it].append(f"{a} {b}")
for _ in range(q):
    i=input()
    if i not in mp:
        print("nobody")
    elif len(mp[i]) > 1:
        print("ambiguous")
    else:
        print(mp[i][0])
