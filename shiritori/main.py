n = int(input())

a = [input() for i in range(n)]

seen = set()
seen.add(a[0])
for i,(s,t) in enumerate(zip(a, a[1:])):
    if t[0] != s[-1] or t in seen:
        print(f"Player {2-(i&1)} lost")
        break
    seen.add(t)
else:
    print("Fair Game")
