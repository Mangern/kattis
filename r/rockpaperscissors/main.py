f = False
while True:
    llll = input()
    if llll == "0":
        break
    n, k = map(int, llll.split())

    if f:
        print()
    else:
        f = True

    win = [0 for i in range(n)]
    loss =[0 for i in range(n)] 
    for i in range(k * n * (n - 1) // 2):
        p1, m1, p2, m2 = input().split()
        p1 = int(p1) - 1
        p2 = int(p2) - 1

        if m1 == m2:
            continue

        if m1 == "rock":
            if m2 == "scissors":
                win[p1] += 1
                loss[p2] += 1
            else:
                win[p2] += 1
                loss[p1] += 1
        if m1 == "scissors":
            if m2 == "paper":
                win[p1] += 1
                loss[p2] += 1
            else:
                win[p2] += 1
                loss[p1] += 1
        if m1 == "paper":
            if m2 == "rock":
                win[p1] += 1
                loss[p2] += 1
            else:
                win[p2] += 1
                loss[p1] += 1
    for i in range(n):
        if win[i]+ loss[i] == 0:
            print("-")
        else:
            print(f"{win[i] / (loss[i] + win[i]):.3f}")
