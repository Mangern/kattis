input()
p = float(input())
n = int(input())
s = sum(0 if input() == "plast" else 1 for _ in range(n))

print("Jebb" if s / n <= p else "Neibb")
