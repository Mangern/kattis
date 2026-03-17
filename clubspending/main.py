spend={}
for _ in range(int(input())):
    nm, dol = input().split()
    cent=int(dol[1:].replace('.',''))
    spend[nm]=spend.get(nm,0)+cent
    print(f"{nm} ${spend[nm]//100}.{spend[nm]%100:02d}")
