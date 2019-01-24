m = 5000001
tot = [0]*m


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


for i in range(1, 2500, 2):
    for j in range(2, 2500, 2):
        if gcd(i, j) != 1:
            continue
        wi = i*i+j*j+2*i*j
        l = wi+abs(i*i-j*j)
        a = 1
        # (i,j)
        while a*l < m:
            tot[a*l] += 1
            a += 1
        if wi > m:
            break
    if i*i > m:
        break

for i in range(1, m):
    if tot[i] > 1:
        tot[i] = 0
    tot[i] += tot[i-1]
for p in range(int(input())):
    print(tot[int(input())])
