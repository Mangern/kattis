import random
import sys

def geninp():
    T = 100000

    with open("input.txt", "w") as f:
        f.write(f"{T}\n")

        for _ in range(T):
            pts = [random.randint(-10, 10) for _ in range(8)]
            inp = " ".join(map(str,pts))
            f.write(f"{inp}\n")

def compare():
    pass

if __name__ == "__main__":
    if len(sys.argv) == 1:
        print(f"Usage: {sys.argv[0]} OPTION")
        print(f"   OPTION = ['gen', 'compare']")
        exit(1)

    if sys.argv[1] == "gen":
        geninp()
    else:
        compare()
