def isp(s: str):
    return len([c for c in s if c.isalnum() and not c.isnumeric()])>0 and len([c for c in s if c.isnumeric()])>0
ws = input().split()
ws = [w if not isp(w) else "*"*len(w) for w in ws]
print(" ".join(ws))
