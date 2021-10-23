m = 10**7
cri = [0]*m
pri = []
for i in range(2, m):
    if cri[i] == 0:
        cri[i] = i
        pri.append(i)
        for j in range(i*i, m, i):
            cri[j] = i
print(len(pri))


def copa(a, b):
    mu = a*b
    res = 0
    while mu <= m:
        me = mu
        while me <= m:
            if me > res:
                res = me
            me *= b
        mu *= a
    return res


def copb(a, b):
    mu = a
    res = 0
    while True:
        lo, hi = 1, 1
        while mu*b**hi < m:
            hi *= 2
        while hi > lo:
            mid = (1+lo+hi)//2
            if mu*b**mid > m:
                hi = mid-1
            else:
                lo = mid
        resu = mu*b**lo
        if resu <= m and resu > res:
            res = resu
        mu *= a
        if mu*b > m:
            break
    return res


resp = 0
for i in range(len(pri)):
    for j in range(i+1, len(pri)):
        if pri[i]*pri[j] > m:
            break
        if pri[i]*pri[i]*pri[j] > m:
            resp += pri[i]*pri[j]
        else:
            resp += copa(pri[i], pri[j])
print(resp)
