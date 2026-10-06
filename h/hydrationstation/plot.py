from sys import argv
import matplotlib.pyplot as plt
data = [tuple(map(float, line.split())) for line in open(argv[1]).read().splitlines()]

x = [t[0] for t in data]
y = [t[1] for t in data]

plt.plot(x, y)
plt.show()

