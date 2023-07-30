def get_val(c):
    if c == " ":
        return 0
    return ord(c) - ord('a')+1

def get_chr(v):
    if v == 0:
        return " "
    return chr(ord('a')+v-1)

for _ in range(int(input())):
    msg = input()
    t = msg[0]
    msg = msg[2:]

    ans = [msg[0]]
    sm = get_val(msg[0]) if t == 'e' else 0
    for c in msg[1:]:
        curr = c if t == 'e' else ans[-1]
        sm += get_val(curr)
        sm %= 27
        if t == 'e':
            ans.append(get_chr(sm))
        else:
            ans.append(get_chr((get_val(c)-sm)%27))
    print("".join(ans))
