from sys import stdin

def solve(lines):
    lines.sort(key=lambda s: s[::-1])
    mlen = max(map(len,lines))
    print("\n".join(f"{s:>{mlen}}" for s in lines))


lines = []
for line in stdin.readlines():
    if not line.strip():
        solve(lines)
        print()
        lines.clear()
    else:
        lines.append(line.strip())

solve(lines)
