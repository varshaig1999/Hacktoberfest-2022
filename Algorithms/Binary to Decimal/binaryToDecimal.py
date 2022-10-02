# Binary Number represented as a string
n = "1100"

def binaryToDecimal(n):

    res = 0
    l = len(n)

    for i in range(len(n) - 1, -1, -1):
        if n[i] == "1":
            res += (1 << (l - i - 1))
    
    return res

print(binaryToDecimal(n))
