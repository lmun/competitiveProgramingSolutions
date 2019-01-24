from itertools import *
matiti = 0
x, y = map(int, input().split())
lim = 2*x
lim2 = lim//2-1
for c in permutations(range(lim), lim//2):
    if c[0] != max(c):
        continue
    for j in range(lim):
        if j not in c:
            break
    mi = ma = c[0]+c[-1]
    s = set()
    s.add(c[0]+c[-1])
    for i in range(lim2):
        d = c[i]+c[i+1]
        if d in s:
            break
        s.add(d)
        mi = min(mi, d)
        ma = max(ma, d)
    else:
        # print(c, mi, ma, ma-mi, s, j)
        titi = set(map(lambda x: ma+j-x, s))
        wawa = titi | set(c)
        # print(len(set(map(lambda x: ma+j-x, s)) | s), set(map(lambda x: ma+j-x, s)))
        if max(wawa) == lim-1 and len(wawa) == lim and ma+j+3==y:
            if min(titi) >= matiti:
                # print(c, titi, min(titi))
                matiti = min(titi)
                for i in range(lim2):
                    print(ma+j-c[i]-c[i+1]+1, c[i]+1, c[i+1]+1, end="", sep="")
                print(ma+j-c[lim2]-c[0]+1, c[lim2]+1, c[0]+1, sep="")
