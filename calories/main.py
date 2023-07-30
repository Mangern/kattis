from itertools import chain

def ints(x):
    return int(x[:-1])

def convog(x, much):
    if x[-1] == 'g':
        return ints(x)*much
    elif x[-1] == 'C':
        return ints(x)
    return x

def convop(x, tot):
    x = ints(x) / 100
    return x * tot

while True:

    smft = 0
    smtot = 0
    while True:
        s = input()
        if s == '-':
            break

        vals = s.split()
        ft = vals[0]
        prts = vals[1:4]
        alc = vals[4]

        ft = convog(ft, 9)
        prts = [convog(x, 4) for x in prts]
        alc = convog(alc, 7)

        nmcals = sum(x for x in chain([ft],prts,[alc]) if type(x) != str)
        nmproc = sum(ints(x) for x in chain([ft], prts, [alc]) if type(x) == str)
        tot = nmcals / (1 - nmproc/100)
        if type(ft) == str:
            ft = convop(ft,tot)

        prts = [convop(x, tot) if type(x) == str else x for x in prts]
        if type(alc) == str:
            alc = convop(alc,tot)
        smft += ft
        smtot += sum(chain([ft],prts,[alc]))
    if smtot == 0:
        break
    print(f"{round(100*smft/smtot)}%")
