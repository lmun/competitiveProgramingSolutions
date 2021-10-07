a = 2
limi = 10**6
res = 0
while True:
    a += 1
    if a*a-(a-2)**2 > limi:
        break
    lo, hi = 1, a
    while hi > lo:
        mid = (lo+hi)//2
        if a*a-mid*mid > limi:
            lo = mid+1
        else:
            hi = mid
    # print(a, lo, (a-lo)//2)
    res += (a-lo)//2
print(res)
