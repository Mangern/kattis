import matplotlib.pyplot as plt
import sys

from numpy import hypot

fn = sys.argv[1]

lines = open(f"{fn}.in").readlines()
n = int(lines[0])
pts = [tuple(map(float, line.split())) for line in lines[1:]]
assert len(pts) == n

xs = [pt[0] for pt in pts]
ys = [pt[1] for pt in pts]

lines = open(f"{fn}.out").readlines()
answer = list(map(int, lines))

xans = [pts[i][0] for i in answer]
yans = [pts[i][1] for i in answer]

length = 0

xans.append(pts[answer[0]][0])
yans.append(pts[answer[0]][1])

for i in range(1, len(xans)):
    length += hypot(xans[i] - xans[i-1], yans[i] - yans[i-1])

plt.title(length)
plt.scatter(xs, ys)
plt.plot(xans, yans)
plt.show()
