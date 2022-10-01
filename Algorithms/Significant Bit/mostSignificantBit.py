# Number
n = 5

# Function to calculate most significant bit
def msb(n):
    if n == 0:
        return -1
    
    for i in range(32, -1, -1):
        if (1 << i) & n:
            return (i + 1)

print(msb(n))
