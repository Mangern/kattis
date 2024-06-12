n, k = map(int, input().split())

for i in range(k):
    n = (n+1) // 2
    if n <= 1:
        break
else:
    print("You will become a flying monkey!")
    exit(0)

print("Your wish is granted!")
