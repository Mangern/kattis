
def print_strs(i,s):
    if i == 1:
        print(f"1 bottle of {s} on the wall, 1 bottle of {s}.")
        print(f"Take it down, pass it around, no more bottles of {s}.")
    elif i == 2:
        print(f"2 bottles of {s} on the wall, 2 bottles of {s}.")
        print(f"Take one down, pass it around, 1 bottle of {s} on the wall.")
        print()
    else:
        print(f"{i} bottles of {s} on the wall, {i} bottles of {s}.")
        print(f"Take one down, pass it around, {i-1} bottles of {s} on the wall.")
        print()



n = int(input())
s = input()

for i in range(n,0,-1):
    print_strs(i,s)
