n=int(input())
ys=[int(input()) for _ in range(n)]
ys.sort()
sy = ys[0]
top=0
for i in range(1, n):
    top += i * ys[i] - sy
    sy += ys[i]
print(top / (n * sy))
