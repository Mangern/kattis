s = input()
c = [4,3,2,7,6,5,0,4,3,2,1]
ans = 0
for i in range(len(s)):
    if s[i] == '-':
        continue
    ans += c[i] * int(s[i])
print(1 if ans%11==0 else 0)
