ws = set(input().lower() for _ in range(int(input())))
print("Hi, how do I look today?" if all(w.lower() in ws for w in input().split()) else "Thore has left the chat")
