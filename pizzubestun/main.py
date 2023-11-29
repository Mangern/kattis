a = [int(input().split()[-1]) for _ in range(int(input()))]
a.sort()
a = a[::-1]
a.append(a[-1])
ans = sum(x for x, y in zip(a[::2], a[1::2]))

print(ans)

