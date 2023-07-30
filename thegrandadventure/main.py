match = {
    't': '|',
    'j': '*',
    'b': '$'
}
for _ in range(int(input())):
    s = input()
    st = []

    for c in s:
        if c in ['t','j','b']:
            if len(st)==0 or match[c] != st[-1]:
                print("NO")
                break
            else:
                st.pop()
        elif c != '.':
            st.append(c)
    else:
        print("YES" if len(st)==0 else "NO")
