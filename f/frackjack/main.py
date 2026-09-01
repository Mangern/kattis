a=int(input())
b=int(input())
if a == b or min(a,b) > 21:
    print("Jack")
elif a > 21:
    print("Bertil")
elif b > 21:
    print("Alice")
else:
    print("Alice" if a > b else "Bertil")
