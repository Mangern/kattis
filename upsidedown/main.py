input()
ws = [s[::-1] for s in input().split()]
ws.sort(reverse=True)
print(" ".join(ws))
