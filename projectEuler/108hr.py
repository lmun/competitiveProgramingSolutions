from math import sqrt
li = 100000
cri = [0]*li
pri = []
for i in range(2, li):
    if cri[i] == 0:
        cri[i] = i
        pri.append(i)
        for j in range(i*i, li, i):
            cri[j] = i

for _ in range(int(input())):
    tinu = int(input())
    r = 1
    if tinu >= li:
        for p in pri:
            if tinu % p == 0:
                tis = 0
                while tinu % p == 0:
                    tinu //= p
                    tis += 1
                r *= 2*tis+1
                if tinu < li:
                    break
        else:
            if r == 1:
                ttt = int(sqrt(tinu))
                if ttt*ttt == tinu:
                    r = 3
                else:
                    r = 5
        if tinu < li:
            while tinu > 1:
                tis = 0
                wa = cri[tinu]
                while tinu % wa == 0:
                    tinu //= wa
                    tis += 1
                r *= 2*tis+1
        print(r//2+1)
    else:
        while tinu > 1 and tinu < li:
            tis = 0
            wa = cri[tinu]
            while tinu % wa == 0:
                tinu //= wa
                tis += 1
            r *= 2*tis+1
        print(r//2+1)
