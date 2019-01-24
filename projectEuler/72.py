m = 1000001
cri = [0]*m
war = [0]*m
for i in range(2, m):
    if cri[i] == 0:
        cri[i] = i
        for j in range(i*i, m, i):
            cri[j] = i


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


res = 0
for i in range(2, m):
    res += toti(i)
    war[i] = res
for _ in range(int(input())):
    print(war[int(input())])
