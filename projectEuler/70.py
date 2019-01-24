m = int(input())+1
cri = [0]*m
for i in range(2, m):
    if cri[i] == 0:
        cri[i] = i
        for j in range(i*i, m, i):
            cri[j] = i


def samedigi(a, b):
    conb = [0]*10
    for d in str(a):
        conb[int(d)] += 1
    for d in str(b):
        conb[int(d)] -= 1
    for i in range(10):
        if conb[i] != 0:
            return False
    return True


def toti(n):
    t = 1
    while n > 1:
        d = cri[n]
        c = 0
        while n % d == 0:
            n //= d
            c += 1
        t *= (d-1)*(d**(c-1))
    return t


mini = 100
minn = []
for i in range(2, m):
    t = toti(i)
    if samedigi(i, t) and i/t < mini:
        # print(i, t, i/t)
        mini = i/t
        minn.append(i)
print(minn)
