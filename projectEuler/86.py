#!/usr/bin/env python3.5
from math import sqrt

# m = 52500
m = 12*10**5
tot = [0]*m


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


arr = list()
for i in range(1, 15000, 2):
    for j in range(2, 15000, 2):
        if gcd(i, j) != 1:
            continue
        l = i*i+j*j+2*i*j+abs(i*i-j*j)
        a = 1
        # print(i*i+j*j,2*i*j,abs(i*i-j*j))
        while a*l < m:
            trip = sorted(((i*i+j*j)*a, 2*a*i*j, abs((i*i-j*j)*a)))
            arr.append(trip)
            tot[a*l] += 1
            a += 1
        if i*i+j*j+2*i*j > m:
            break
    if i*i > m:
        break
tria = set()


def uwu(a, b):
    i = b//2
    c = 0
    while i-c > 0 and b-i+c < sauri:
        tria.add(tuple(sorted((a, i-c, b-i+c))))
        c += 1
    return 0


for _ in range(int(input())):
    sauri = int(input())+1
    tria = set()
    se = set()
    aeae = [ar for ar in arr if ar[0] < sauri]
    aeae = [ar for ar in aeae if ar[1] < 2*sauri]
    # aeae.sort(key = lambda val:val[1])
    res = 0
    for ar in aeae:
        ne = uwu(ar[0], ar[1])
        if ar[1] < sauri:
            uwu(ar[1], ar[0])
        # print(ar,ne)
        res += ne
    # print(len(aeae))
    # print(res, len(tria))
    for t in tria:
        # print(t)
        pass
    waw = [ar for ar in tria if int(sqrt((ar[0]+ar[1])**2+ar[2]*ar[2]))**2 == (ar[0]+ar[1])**2+ar[2]*ar[2]]
    # print(res, len(waw))
    print(len(waw))
