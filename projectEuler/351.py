m = 10**8+1
cri = [0]*m
nums = [0]*m
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


x = (m*(m-1))//2
y = sum(toti(a) for a in range(1, m))
print(x, y, x-y)
print(6*(x-y))
