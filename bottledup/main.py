s, v1, v2 = map(int, input().split())

i = 0
ans = None 
ansi = None
while i * v1 <= s:
    t = s - i * v1

    if t % v2 == 0:
        if ans is None or i + t//v2 < ans:
            ans = i + t//v2
            ansi = i
    i += 1

if ans is None:
    print("Impossible")
else:
    print(ansi, (s - ansi * v1) // v2)
