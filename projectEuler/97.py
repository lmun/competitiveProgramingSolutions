def modpow(b, e, m):
    r = 1
    while e > 0:
        if e % 2 == 1:
            r = (r*b) % m
        e //= 2
        b = (b*b) % m
    return r


mo = 10**15
tot = 0
for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    tot += (a*modpow(b, c, mo)+d)
    tot %= mo
pala = "00000000000000"+str(tot)
print(pala[-12:])
