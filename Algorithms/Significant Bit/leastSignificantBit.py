# Number
n = 5

# Function to calculate least significant bit
def msb(n):
    if n == 0:
        return -1

    for i in range(0, 31):
        if (1 << i) & n:
            return (i + 1)

print(msb(n))
