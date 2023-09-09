n = int(input())
a = [tuple(map(int, input().split())) for i in range(n)]

sm = 0
for x, y in a:
    sm += x
    if sm < y:
        print("impossible")
        break
else:
    print("possible")

