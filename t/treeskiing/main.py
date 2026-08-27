n=int(input())
c=sum(1 for c in input().split() if c == 'W')
ret=1
for i in range(c):
    ret *= (n - i)
    ret //= i + 1
print(ret - 1)
