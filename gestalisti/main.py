s=set()
for _ in range(int(input())):
    t,n=input().split()
    if t == '+':
        s.add(n)
    if t== '-':
        s.remove(n)
    if t=='?':
        print("Jebb" if n in s else "Neibb")
