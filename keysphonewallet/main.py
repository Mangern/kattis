gl = {"keys", "phone", "wallet"}
s = set(input() for _ in range(int(input())))
r = gl - s

if not len(r):
    print("ready")
else:
    print("\n".join(sorted(gl - s)))
