suma = 0
for a in range(3, 1001):
# for a in range(7, 8):
    m = a*a
    visi = set()
    sa = a+1
    aa = a-1
    ae = 1
    se = 1
    # visi.add(m*ae+se)
    ma = 2
    c = 0
    while True:
        if m*ae+se in visi:
            # print(m*ae+se)
            break
        visi.add(m*ae+se)
        ma = max((ae+se) % m, ma)
        # print(c, ma, ae, se)
        ae *= aa
        ae %= m
        se *= sa
        se %= m
        c += 1
    # print(a, ma, c, m)
    print(a, ma)
    suma += ma
print(suma)
