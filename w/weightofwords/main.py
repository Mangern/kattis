l, w = map(int, input().split())

if w < l or 26 * l < w:
    print("impossible")
    exit()

a = [1 for i in range(l)]

ptr = l - 1
while sum(a) < w:
    a[ptr] += 1
    if a[ptr] == 26:
        ptr -= 1

print("".join(map(lambda x: chr(ord('a')+x-1), a)))

