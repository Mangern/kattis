def all_eq(l):
    return all(x == l[0] for x in l)

layers = [list(map(int,input().split()))[1:]]

while len(layers[-1]) > 1:
    nl = []
    for x,y in zip(layers[-1], layers[-1][1:]):
        nl.append(y-x)
    layers.append(nl)


for i in range(len(layers)-2, -1, -1):
    layers[i].append(layers[i][-1] + layers[i+1][-1])

for d in range(len(layers)):
    if all_eq(layers[d]):
        break

print(d, layers[0][-1])
