from math import factorial
mod = 10**9+7


def modfac(nu):
    re = 1
    for x in range(2, nu+1):
        re *= x
        re %= mod
    return re


n, m = map(int, input().split())
suma = 0
n += 1
for i in range(n//(m+1)+1):
    a = n-(m-1)*i
    b = 2*i
    f1 = modfac(a)
    f2 = modfac(b)
    f3 = modfac(a-b)
    res = f1//(f2*f3)
    suma += res
print(suma)
