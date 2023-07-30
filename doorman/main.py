d = int(input())
s = input()
n = len(s)

dl = 0
ans = 0
i = 0
while i < n:
    if i < n - 1 and s[i] != s[i+1]:
        ans += 2
        i += 2
        continue
    if s[i] == 'W' and dl < d:
        ans += 1
        dl += 1
        i += 1
        continue
    if s[i] == 'M' and dl > -d:
        ans += 1
        dl -= 1
        i += 1
        continue
    break
print(ans)
