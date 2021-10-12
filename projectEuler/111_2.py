m = 10**7
cri = [0]*m
pri = []
for i in range(2, m):
    if cri[i] == 0:
        pri.append(i)
        cri[i] = i
        for j in range(i*i, m, i):
            cri[j] = i

def esprimo(nu):
    for p in pri:
        if p*p > nu:
            return True
        if nu % p == 0:
            return False
    return True

nus = set()
de = 10
for i in range(1, 10):
    for j in range(10):
        a = [i]*(de-1)+[j]+[i]*15
        te = ''.join(map(str, a))
        for k in range(de):
            wa = int(te[k:k+de])
            # print(wa)
            if esprimo(wa):
                nus.add(wa)

for i in [0, 2, 8]:
    for j in range(1, 10, 2):
        for p in range(10):
            for k in range(9):
                a = [i]*k+[p]+[i]*(8-k)+[j]
                if a[0] == 0:
                    continue
                wewe = int(''.join(map(str, a)))
                if esprimo(wewe):
                    nus.add(wewe)
                    # print(wewe)
print(sorted(nus))
print(sum(nus))
