a=int(input())
b=int(input())
vis=set()


for x in range(-360, 361):
    for y in range(-360, 361):
        vis.add((a * x + b * y) % 360)
print(len(vis))
