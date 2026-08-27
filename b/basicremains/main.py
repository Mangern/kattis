def to_str(n, b):
    if n < b:
        return "0123456789"[n]
    return to_str(n // b, b) + to_str(n % b, b)

while True:
    s = input()
    if s == "0":
        break
    b,p,m = s.split()
    b = int(b)
    p = int(p, b)
    m = int(m, b)
    r = p % m
    print(f"{to_str(r,b)}")
