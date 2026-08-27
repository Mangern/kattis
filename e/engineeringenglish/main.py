seen = set()
while True:
    try:
        s = input().split()
        for w in s:
            if w.lower() in seen:
                print(".", end=" ")
            else:
                print(w, end=" ")
            seen.add(w.lower())

        print()
    except:
        break
