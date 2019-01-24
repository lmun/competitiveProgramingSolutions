def modpow(b, e, m):
    res = 1
    while e > 0:
        if e % 2 == 1:
            res = (res*b) % m
        e //= 2
        b = (b*b) % m
    return res


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
n = 0
for p in pri:
    n += 1
    tt = (modpow(p-1, n, p*p) + modpow(p+1, n, p*p)) % (p*p)
    # print(modpow(p-1, n, p*p), modpow(p+1, n, p*p))
    print(n, p, tt)
    if tt > 10**10:
        break
