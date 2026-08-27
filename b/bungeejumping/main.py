# Floating point arithmetic: submit a bunch of times with minor changes.
g = 9.81
while True:
    k,l,s,m = map(float,input().split())
    if k == 0.0 and l == 0.0 and s == 0.0 and m == 0.0:
        break

    dif = max(0.0, s - l)
    Ek = m * g * s - 0.5*k*dif *dif

    if 2 * m * g * s <= k * dif * dif:
        print("Stuck in the air.")
    else:
        v = Ek / m

        if v <= 50.0:
            print("James Bond survives.")
        else:
            print("Killed by the impact.")

