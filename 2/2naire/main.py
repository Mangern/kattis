while True:
    n,t=input().split()
    if n == "0":
        break
    n=int(n)
    t=float(t)

    E_w = 2**n
    for i in range(n):
        E_q = 2**(n-i-1)

        a = -E_w/(2*(1-t))
        b = E_q / (1-t)
        c = E_w / (2*(1-t)) - t * E_q / (1 - t)

        T_opt = - b / (2 * a)

        if T_opt < t:
            T_opt = t
        if T_opt > 1:
            T_opt = 1

        E_w = a * T_opt * T_opt + b * T_opt + c
    print(f"{E_w:.3f}")
