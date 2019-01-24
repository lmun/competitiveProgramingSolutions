from math import sqrt
bil = 1000000001
totper = 0
for a in range(2, 400000000):
    ra = 3*a*a-2*a-1
    rb = 3*a*a+2*a-1
    sra = int(sqrt(ra))
    srb = int(sqrt(rb))
    p = 3*a
    if sra*sra == ra and p+1 < bil:
        print(a, a+1, sra*float(a+1)/8)
        totper += p+1
    if srb*srb == rb and p-1 < bil:
        print(a, a-1, srb*float(a-1)/8)
        totper += p-1
print(totper)
