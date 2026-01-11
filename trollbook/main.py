n=int(input())
ws = []
for _ in range(n):
    a,b=input().split()
    ws.append((int(b), a))
ws.sort()
for i, s in ws:
    if i > 1:
        print(" ",end="")
    print(s,end="")
print()
