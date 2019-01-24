def isdec(n):
    le = n % 10
    while n > 0:
        d = le
        n //= 10
        le = n % 10
        if n > 0 and le < d:
            return False
    return True


def isinc(n):
    le = n % 10
    while n > 0:
        d = le
        n //= 10
        le = n % 10
        if n > 0 and le > d:
            return False
    return True


r = 0
dec = 9
inc = 9
for i in range(10, 100000):
    if not isinc(i) and not isdec(i):
        r += 1
        print(i, r, 100*r/i)
    if isdec(i):
        dec += 1
    if isinc(i):
        inc += 1
print(inc, dec, r)
