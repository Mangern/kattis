import numpy as np
import matplotlib.pyplot as plt
from random import randint

pts = []

n = int(input())
for _ in range(n):
    x,y = map(int, input().split())
    pts.append((x,y))

xs, ys = zip(*pts)
plt.scatter(xs, ys)
plt.plot(xs, ys)
plt.show()
