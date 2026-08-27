n = float(input())
h = float(input())
x = float(input())
m = float(input())
y = float(input())

# n workers h hours x cubics
# n workers h/x hours 1 cubix
# 1 worker h/x * n hours 1 cubix
# m workers h/x*n/m hours 1 cubix
# m workers h/x*n/m*y hours y cubixs

print(h / x * n / m * y)
