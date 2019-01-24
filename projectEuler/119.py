def sumdigi(nu, b):
    res = 0
    while nu > 0:
        res += nu % b
        nu //= b
    return res


lim = 10**100

resp = []
base = int(input())
for i in range(2, base*100+1):
    for j in range(1, 1000):
        val = i**j
        if val > lim:
            break
        if val > base and sumdigi(val, base) == i:
            # print(i, j, val)
            resp.append(val)
resp.sort()
for a in resp:
    print(a)
print()
