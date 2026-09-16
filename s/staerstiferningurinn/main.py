ans_x=None
ans_y=None

for _ in range(int(input())):
    a, b = map(int,input().split())
    if a != b:
        continue
    if ans_x is None or a * b > ans_x * ans_y:
        ans_x, ans_y = a, b
print(ans_x, ans_y)
