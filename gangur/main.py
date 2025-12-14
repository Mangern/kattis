ans=0
nr=0
for c in input():
    if c == '>':
        nr += 1
    elif c == '<':
        ans += nr
print(ans)
