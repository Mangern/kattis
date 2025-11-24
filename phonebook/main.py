ans = 0
for _ in range(int(input())):
    p=input()
    if p.startswith("+39") and len(p) in [12,13]:
        ans += 1
print(ans)
