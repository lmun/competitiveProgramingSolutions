from math import sqrt

sumi = 0
c = 2
nn = int(input())
pp = int(input())
for ooo in range(1, nn+1):
    c = ooo
    ra = int(sqrt(c))
    if ra*ra == ooo:
        continue
    sumi -= ra
    wata = 0
    while ra > 0:
        sumi += ra % 10
        wata += 1
        ra //= 10
    p = 0
    for a in range(pp-wata+1):
        x = 0
        y = (x+1)*(20*p+(x+1))
        while y <= c:
            x += 1
            y = (x+1)*(20*p+(x+1))
        y = x*(20*p+(x))
        p = 10*p+x
        sumi += x
        # print(x, end=" ")
        c = c-y
        c *= 100
print(sumi)
