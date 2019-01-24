def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


m = 10**7
cri = [0]*m
for i in range(2, m):
    if cri[i] == 0:
        cri[i] = i
        for j in range(i*i, m, i):
            cri[j] = i
total = 0
ttt = list()
enc = 1
limi = 120000
radres = [set() for _ in range(limi)]
calrad = [False]*limi



def rad(s):
    if calrad[s]:
        return radres[s]
    res = set()
    while s > 1:
        pp = cri[s]
        res.add(pp)
        while s % pp == 0:
            s //= pp
    radres[s] = res
    calrad[s] = True
    return res


def radol(s):
    res = 1
    while s > 1:
        pp = cri[s]
        while s % pp == 0:
            s //= pp
        res *= pp
    return res


allrad = [radol(i) for i in range(limi+100)]

for i in range(2, limi):
    if allrad[i] > limi:
        continue
    for j in range(1, i):
        if allrad[j] > limi:
            continue
        if gcd(i, j) == 1:
            s = i+j
            if s >= limi:
                break
            if allrad[s]*allrad[j]*allrad[i] < s:
                total += s
                print(enc, i, j, s)
                enc += 1
            if gcd(s, i) != 1 or gcd(s, j) != 1:
                print(i, j, s % i, s % j)
                pass
print(total)
