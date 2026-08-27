s=input()
loc = [i for i, c in enumerate(s[:-1]) if c == 'S' and s[i+1] == 'S']
for i in loc:
    t = list(s.lower())
    t[i] = 'B'
    t[i+1] = ''
    print("".join(t))
print(s.lower())
