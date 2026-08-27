for _ in range(int(input())):
    state = int(input(), 8)

    def get_pos(i, j):
        k = i * 3 + j
        if (state & (1<<k)) == 0:
            return ""
        return "X" if (state & (1<<(9+k))) else "O"

    def get_winner(arr):
        if all(x == arr[0] for x in arr) and arr[0] != "":
            return arr[0]
        return None

    cnt_found = 0
    for i in range(3):
        rw = []
        cl = []
        dd = []
        du = []
        for j in range(3):
            if get_pos(i,j) != "":
                cnt_found += 1
            rw.append(get_pos(i,j))
            cl.append(get_pos(j,i))
            dd.append(get_pos(j,j))
            du.append(get_pos(2-j,j))
        winner = get_winner(rw) or get_winner(cl) or get_winner(dd) or get_winner(du)
        if winner:
            print(f"{winner} wins")
            break
    else:
        print("Cat's" if cnt_found == 9 else "In progress")

