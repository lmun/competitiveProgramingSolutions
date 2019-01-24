
def trirep(a):
    global mx
    sa = str(a)
    conb = [0]*10
    for d in sa:
        conb[int(d)] += 1
    for y in range(10):
        if conb[y] == 3:
            xx = 0
            for c in "123456789":
                if cri[int(sa.replace(str(y), c))] == 0:
                    xx += 1
            if sa[0] != str(y) and cri[int(sa.replace(str(y), '0'))] == 0:
                xx += 1
            # xx = sum(1 if cri[int(sa.replace(str(y), c))] == 0 else 0 for c in "0123456789")
            if xx > 7:
                print(a, y, xx)


"""
    for y in range(10):
        if conb[y] == 3:
            rep = str(a).replace(str(y), '.')
            # print(rep)
            if rep not in tata:
                tata[rep] = 1
            else:
                tata[rep] += 1
                if tata[rep] >= 5:
                    print(rep, tata[rep], a)
                    mx = tata[rep]
    # return any(b == 3 for b in conb)
"""

mx = 0
tata = {}
m = 10**7
pri = []
cri = [0]*m
for i in range(2, m):
    if cri[i] == 0:
        pri.append(i)
        for j in range(i*i, m, i):
            cri[j] = i
for p in pri:
    if p < 56000 or p > 57000:
        pass
        # continue
    trirep(p)
    # print(p)
