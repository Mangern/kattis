n = int(input())
d = {}
for _ in range(n):
    input()
    s = input()
    d[s] = d.get(s,0)+1
for k, v in d.items():
    print(k,v)
