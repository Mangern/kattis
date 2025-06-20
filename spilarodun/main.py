n = int(input())

cards = []

catmap = {
    "Skrimsli":
        [
            "Venjulegt",
            "Ahrifa",
            "Bodunar",
            "Samruna",
            "Samstillt",
            "Thaeo",
            "Penduls",
            "Tengis"
        ],
    "Galdur":
        [
            "Venjulegur",
            "Bunadar",
            "Svida",
            "Samfelldur",
            "Bodunar",
            "Hradur"
         ],
    "Gildra":
        [
            "Venjuleg",
            "Samfelld",
            "Mot"
        ],
    "Annad": []
}

catord = ["Skrimsli", "Galdur", "Gildra", "Annad"]


for _ in range(n):
    s = input()
    name, id, cat, date = s.split(", ")
    if "Annad" in cat:
        c1, c2 = 3, 0
    else:
        cs1, cs2 = cat.split(" - ")
        c1 = catord.index(cs1)
        c2 = catmap[cs1].index(cs2)

    y,m,d = map(int, date.split("-"))
    cards.append((name, int(id), (c1, c2), (y,m,d)))

idxs = ["nafn", "id", "flokkur", "dagsetning"]
ords = [idxs.index(s) for s in input().split()]

def keyfun(tup):
    return tuple([tup[i] for i in ords])

cards.sort(key=keyfun)

for c in cards:
    print(c[0])
