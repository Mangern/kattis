n = int(input())
a = [int(input()) for _ in range(n)]
print(max(0, min(a) - max(a)//2))
