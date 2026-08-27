n,p,m=map(int,input().split())
score = {input(): 0 for _ in range(n)}

won = False
for i in range(m):
    name,s=input().split()
    s = int(s)

    if name in score:
        score[name] += s
        if score[name] >= p:
            print(f"{name} wins!")
            won = True
            del score[name]

if not won:
    print("No winner!")
