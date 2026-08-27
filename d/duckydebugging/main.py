while True:
    s = input().strip()
    if s == "I quacked the code!":
        exit()
    if s[-1] == '.':
        print("*Nod*")
        continue
    if s[-1] == '?':
        print("Quack!")
        continue
