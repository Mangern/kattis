prv = ""
ans = 0
for _ in range(int(input())):
    s = input()
    if s == "sober" and prv == "drunk":
        ans += 1
    prv = s
print(ans)
