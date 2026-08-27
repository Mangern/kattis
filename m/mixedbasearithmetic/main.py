from sys import stdin

for line in stdin:
    num, i = line.split()
    i = int(i)
    digs = [c for c in num][::-1]

    while i:
        carry = 1
        i -= carry
        prevc = '0'
        mul = 1
        for j in range(len(digs)):
            if ord('0') <= ord(digs[j]) <= ord('9'):
                add = (int(digs[j]) + carry)%10
                carry = (int(digs[j]) + carry)//10
                digs[j] = chr(ord('0')+add)
                if carry == 0 and ord(digs[j]) < ord('9') and mul < i:
                    i -= mul
                    digs[j] = chr(ord(digs[j])+1)
                prevc = '0'
                mul *= 10
            elif ord('a') <= ord(digs[j]) <= ord('z'):
                add = (ord(digs[j]) - ord('a') + carry)%26
                carry = (ord(digs[j]) - ord('a') + carry)//26
                digs[j] = chr(ord('a')+add)
                if carry == 0 and ord(digs[j]) < ord('z') and mul < i:
                    i -= mul
                    digs[j] = chr(ord(digs[j])+1)
                prevc = 'a'
                mul *= 26
            elif ord('A') <= ord(digs[j]) <= ord('Z'):
                add = (ord(digs[j]) - ord('A') + carry)%26
                carry = (ord(digs[j]) - ord('A') + carry)//26
                digs[j] = chr(ord('A')+add)
                if carry == 0 and ord(digs[j]) < ord('Z') and mul < i:
                    i -= mul
                    digs[j] = chr(ord(digs[j])+1)
                prevc = 'A'
                mul *= 26
            else:
                assert False
            if carry == 0:
                break
        else:
            if prevc != '0':
                carry -= 1
                
            digs.append(chr(ord(prevc)+carry))
    print("".join(digs[::-1]))
