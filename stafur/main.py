s = input()
if s == "Y":
    print("Kannski")
else:
    print("Jebb" if s in {"A", "E", "I", "O", "U"} else "Neibb")
