n = int(input())

cnt = [0 ,0, 0]

for _ in range(n):
    ar = input().split()
    for j, c in enumerate(ar):
        if c == 'J':
            cnt[j] += 1

print(min(cnt))
