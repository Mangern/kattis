s = input()

ans = s[:1]

for i in range(1,len(s)):
    if s[i] == ans[-1]:
        continue
    ans += s[i]

print(ans)
