def write(code, state):
    a, b = state

    for i in range(7):
        if code & (1<<i):
            b = 1 - b
        else:
            a = 1 - a
    return (a,b)


while True:
    try:
        s = input()
        state = (0,0)
        for c in s:
            state = write(ord(c), state)
        print("free" if state == (0,0) else "trapped")
    except:
        break
