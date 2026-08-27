dif = set("ABCDEFGHIJKLMNOPQRSTUVWXYZ") - set(input())
if not dif:
    print("Alphabet Soup!")
else:
    print("".join(sorted(dif)))
