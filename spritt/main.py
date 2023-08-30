n, x = map(int, input().split())

for i in range(n):
    a = int(input())
    x -= a

print("Jebb" if x >= 0 else "Neibb")
