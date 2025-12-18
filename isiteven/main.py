n,k=map(int,input().split())
have=0

for i in range(n):
    x = int(input())
    while x % 2 == 0:
        have += 1
        x //= 2

print(1 if have >= k else 0)
