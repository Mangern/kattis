tot = int(input())
n = int(input())
tot *= n

s = sum(sum(1 for c in input() if c == '.') for _ in range(n))

print(s/tot)
