input()
ws = input().split()
dick = {}
for _ in range(int(input())):
    a,b=input().split()
    dick[a] = b
ws = [dick[w] for w in ws]
print(" ".join(ws))
