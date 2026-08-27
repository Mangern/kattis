input()
pt = (0, 0)

pts = []

for w in input().split():
    d = int(w[1:])
    delta = (0, 1) if w[0] == 'N' else\
            ((0,-1) if w[0] == 'S' else
            ((1, 0) if w[0] == 'E' else
            (-1,0) ))
    pts.append(pt)
    pt = (pt[0] + d * delta[0], pt[1] + d * delta[1])

pts.append(pt)

A = abs(sum(pt1[0] * pt2[1] - pt2[0] * pt1[1] for pt1, pt2 in zip(pts, pts[1:]))//2)
print(f"THE AREA IS {A}")
