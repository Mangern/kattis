from math import sqrt

def cosine(v1, v2):
    dot = v1[0] * v2[0] + v1[1] * v2[1]

    return dot 

for _ in range(int(input())):
    print(f"Case #{_+1}: ", end="")
    x1, y1, x2, y2, x3, y3 = map(int, input().split())

    if len(set([(x1, y1), (x2, y2), (x3, y3)])) != 3:
        print("not a triangle")
        continue

    if x1 == x2 == x3:
        print("not a triangle")
        continue

    p1 = (x1, y1)
    p2 = (x2, y2)
    p3 = (x3, y3)

    p1, p2, p3 = sorted([p1,p2,p3])

    x1, y1 = p1
    x2, y2 = p2
    x3, y3 = p3

    x2 -= x1
    x3 -= x1
    x1 = 0

    y2 -= y1
    y3 -= y1
    y1 = 0


    if y2 * x3  == y3 * x2:
        print("not a triangle")
        continue

    min_cos = [
        cosine((x2,y2), (x3, y3)),
        cosine((-x2, -y2), (x3 - x2, y3 - y2)),
        cosine((-x3, -y3), (x2 - x3, y2 - y3))
    ]

    #print(min_cos)
    min_cos = min(min_cos)

    if abs(min_cos) == 0:
        ans1 = "right"
    elif min_cos < 0:
        ans1 = "obtuse"
    else:
        ans1 = "acute"

    s1 = (x2 * x2 + y2 * y2)
    s2 = (x3 * x3 + y3 * y3)
    s3 = ((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3))

    if len(set([s1,s2,s3])) == 3:
        ans2 = "scalene"
    else:
        ans2 = "isosceles"

    print(ans2, ans1, "triangle")
