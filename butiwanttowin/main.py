n = int(input())
a = sorted(map(int,input().split()))

s = sum(a)

x = a[-2]

for i in range(n - 2):
    x += a[i]
    if x * 2 > s:
        print(i + 1)
        exit()
print("IMPOSSIBLE TO WIN")
