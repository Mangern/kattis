s = input()
d = s[0]
st = set(s)
n = int(input())
for i in range(n):
    b = input()
    a = set(b)
    if len(b) >= 4 and d in a and len(a.difference(st))==0:
        print(a)
    
