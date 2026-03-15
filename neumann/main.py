num=[]
for _ in range(int(input())):
    num=[x for x in num] + [num]
print(f"{num}".replace("[", "{").replace("]", "}").replace(" ", ""))
