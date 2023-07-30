from sys import stdin
ws = set()
for line in stdin:
    a = line.split()
    for w in a:
        ws.add(w)

ws = list(ws)
ans = set()
for w in ws:
    for v in ws:
        if w != v:
            ans.add(w+v)

for w in sorted(list(ans)):
    print(w)
            
