def val(s):
    if len(s)==3:
        return 9
    if s[0] == 'J':
        return 10
    if s[0] == 'Q':
        return 11
    if s[0] == 'K':
        return 12
    if s[0] == 'A':
        return 0
    return int(s[0])-1
n = int(input())
cnts = [4] * 13
for _ in range(n):
    s = input()
    cnts[val(s)] -= 1

print(max(cnts)/sum(cnts))
