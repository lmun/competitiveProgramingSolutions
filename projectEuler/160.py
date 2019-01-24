i = 2
n = 3
mod = 10**5
se = set()
# while (i, n % mod) not in se:
while n <= 10**6:
    se.add((i % mod, n % mod))
    i *= n
    while i % 10 == 0:
        i //= 10
    i %= 10**18
    n += 1
print(i % mod, n)
na = n % mod
while n % mod != 0:
    i *= n
    while i % 10 == 0:
        i //= 10
    i %= mod
    n += 1
print(i)
