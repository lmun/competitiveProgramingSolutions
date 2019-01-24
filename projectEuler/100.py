x, y = 1, 1
while y < 10**12:
    x, y = 3*x+2*y-2, 4*x+3*y-3
    print(x, y)
