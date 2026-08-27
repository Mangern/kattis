input()
fl = False
for _ in range(3):
    if "7" not in input():
        fl = True

print(0 if fl else 777)
