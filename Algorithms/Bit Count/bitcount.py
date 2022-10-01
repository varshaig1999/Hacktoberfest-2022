# Number to count the set bits (32 bit number)
n = 12

def bitcount(n):
    count = 0

    for i in range(32):
        if n & (1 << i):
            count += 1
    return count

print(bitcount(n))

"""
Input - 12 (1 1 0 0)
Output - 2 
"""
