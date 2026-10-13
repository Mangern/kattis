from random import randint
for _ in range(int(input())):
    for i in range(100):
        print("FT"[randint(0,1)])
        a = input()
        print("F" if a == "T" else "T")
        input()
