def invinum(n):
    r = 0
    while n > 0:
        r *= 10
        r += n % 10
        n //= 10
    return r


def soloimp(n):
    while n > 0:
        if n % 2 == 0:
            return False
        n //= 10
    return True


ma = 10**9
wa = {}
res, re = 0, 0
r = 0
for i in range(1, ma+1):
    if i % 10 == 0:
        continue
    a = invinum(i)
    if a > i:
        continue
    b = i+a
    if soloimp(b):
        """
        if b in wa:
            wa[b].append(i)
        else:
            wa[b] = [i]
        # print(i, a, b)
        """
        r += 1
# for p in wa:
    # print(p, wa[p])
print(2*r)
