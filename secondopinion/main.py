s = int(input())
hr = s // 3600
s -= hr * 3600
mn = s // 60
s -= mn * 60
print(f"{hr} : {mn} : {s}")
