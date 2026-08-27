d=[]
add=set()
for _ in range(int(input())):
    cmd=input().split()
    if cmd[0] == 'cd':
        if cmd[1] == '..':
            if d:
                d.pop()
        else:
            d.append(cmd[1]) #pyrefly: ignore
    elif cmd[0] == 'nano':
        lst=d+[cmd[1]]
        add.add("/".join(lst))

for p in sorted(add):
    print(f"git add {p}")
print("git commit")
print("git push")
