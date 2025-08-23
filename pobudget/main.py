s = sum(int((input(),input())[1]) for _ in range(int(input())))
if s < 0:
    print("Nekad")
elif s == 0:
    print("Lagom")
else:
    print("Usch, vinst")
