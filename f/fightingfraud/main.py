def fail():
    print("no")
    exit(0)
n=int(input())
cmds=[input().split() for _ in range(n)]

has = set()
done = set()
for cmd, s in cmds:
    if s in done:
        fail()
    if cmd == "pickup":
        if s in has:
            fail()
        has.add(s)
    else:
        if s not in has:
            fail()
        done.add(s)

if len(done) * 2 != n:
    fail()
print("yes")
