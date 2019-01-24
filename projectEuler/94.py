m = 10**9+1


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


for _ in range(int(input())):
    res94 = 0
    m = int(input())
    for i in range(1, 10000, 2):
        for j in range(2, 10000, 2):
            if gcd(i, j) != 1:
                continue
            l1, l2 = i*i+j*j, min(2*i*j, abs(i*i-j*j))
            # (i,j)
            if 2*l2+2*l1 > m:
                break
            if abs(2*l2-l1) < 2:
                print(l1, l2, i, j)
                res94 += 2*l2+2*l1
            # while a*l < m:
                # tot[a*l] += 1
                # a += 1
        if i*i > m:
            break
    print(res94)
"""
res = 0
for i in range(1, m):
    tot[i] = max(tot[i], tot[i-1])
for p in range(int(input())):
    print(tot[int(input())])
print(res)
"""
