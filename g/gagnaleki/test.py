BIG = (1<<(32*4))

def hashfunc(s: str, at: int) -> int:
    """
    first return:  magic
    second return: 2**7 * magic + magic * s[at]

     == (2**7 + s[-1]) * magic

    third return:
    2**7 * (2**7 + s[-1]) * magic + magic * s[-2]
    == (2**7 * (2**7 + s[-1]) + s[-2]) * magic
    == (2**14 + 2**7s[-1] + s[-2]) * magic

    final return:
    (s[0] + 2**7 * s[1] + 2**14 * s[2] + ... + 2**(7(n-1)) * s[n-1]) * magic

    since each s[i] is at most 7 bits we recover s simply by 
    multiplying by the inverse of magic
    """
    magic = 0xb058592efd277ae75f27bd99d1628fbd
    if at >= len(s):
        return magic

    ret = hashfunc(s, at + 1)
    ret = (ret << 7) % BIG
    ret = (ret + (magic * ord(s[at]))%BIG)%BIG

    return ret

ans = hashfunc("password", 0)

print(f"{ans:x}")

