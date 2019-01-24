m = 10**6+4
cri = [0]*m
pri = []
for i in range(2, m):
    if cri[i] == 0:
        cri[i] = i
        pri.append(i)
        for j in range(i*i, m, i):
            cri[j] = i
mo = 1
suma = 0
for p in range(2, len(pri)-1):
    while mo < pri[p]:
        mo *= 10
    f = 0
    c = 0
    while f != pri[p]:
        f += pri[p+1]
        f %= mo
        c += 1
    print(pri[p], f, c*pri[p+1])
    suma += c*pri[p+1]
print(suma)
