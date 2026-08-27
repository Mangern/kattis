def ky(s):
    start = 0
    for i, c in enumerate(s):
        if ord('A') <= ord(c) <= ord('Z'):
            start = i 
            break
    return list(map(ord, s[start:]))
n=int(input())
lst=[input() for _ in range(n)]
lst.sort(key=ky)
print("\n".join(lst))
