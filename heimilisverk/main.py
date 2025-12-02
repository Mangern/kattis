s=set()
for _ in range(int(input())):
    t=input()
    if t in s:
        continue
    print(t)
    s.add(t)
