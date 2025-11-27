def nxt(s):
    lst=[]

    i = 0
    while i < len(s):
        j = i
        while j < len(s) and s[j] == s[i]:
            j += 1

        lst.append(j-i)
        lst.append(s[i])

        i = j

    return "".join(map(str,lst))

s,c=input().split()

m = 0
while s != c:
    s = nxt(s)
    m += 1
print(m)
