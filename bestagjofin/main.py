a = [input().split() for _ in range(int(input()))]

print(max(a, key=lambda x: int(x[1]))[0])
