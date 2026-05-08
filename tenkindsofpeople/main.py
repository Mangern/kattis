def to_digit_arr(s):
    result = []
    for c in s:
        digit = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ".index(c)
        result.append(digit)
    return result

def in_base(digit_arr, b):
    result = 0
    for d in digit_arr:
        result = result * b + d
    return result

for _ in range(int(input())):
    a,b=input().split()
    da = to_digit_arr(a)
    db = to_digit_arr(b)

    mda = max(da)
    mdb = max(db)

    a_values = dict()
    b_values = dict()

    for base in range(2, 7501):
        if mda >= base:
            continue
        a_base = in_base(da, base)
        a_values[a_base] = base

    for base in range(2, 7501):
        if mdb >= base:
            continue
        b_base = in_base(db, base)
        if b_base in a_values:
            print(b_base, a_values[b_base], base)
            break
    else:
        print("CANNOT MAKE EQUAL")
