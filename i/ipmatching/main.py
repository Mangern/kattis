def iptobin(parts):
    ip_bin=[]
    for p in parts:
        ip_bin.append(f"{int(p):08b}")
    return "".join(ip_bin)
n,q=map(int,input().split())
ips=[]
for _ in range(n):
    ip=input()
    parts=ip.split(".")
    lst,mask_len = parts[-1].split("/")
    parts[-1] = lst
    ips.append((iptobin(parts), int(mask_len)))


for _ in range(q):
    ip=iptobin(input().split("."))

    match = -1
    match_len = -1
    for i in range(n):
        table_ip, mask_len = ips[i]
        ok=True
        for j in range(mask_len):
            if ip[j] != table_ip[j]:
                ok=False
                break
        if ok and mask_len > match_len:
            match = i + 1
            match_len = mask_len
    print(match)
