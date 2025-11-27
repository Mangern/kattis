s=input()
ans:list[str]=[]
for c in s:
    if c in "aeiou":
        ans.append(c)
    elif c == "-":
        ans.append("\n")
    elif c in "0123456789":
        ans.append(f"{int(c):b}")
    else:
        ans.append("beepbloop")
print("".join(ans))
