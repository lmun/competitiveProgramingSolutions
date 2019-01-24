lim = 2*10**5+1
cri = [0]*lim
for i in range(2, lim):
    if cri[i] == 0:
        cri[i] = i
        for j in range(i*i, lim, i):
            cri[j] = i

rad = []
for i in range(lim):
    r = 1
    a = i
    while a > 1:
        n = cri[a]
        r *= n
        while a % n == 0:
            a //= n
    rad.append((r, i))
    # print(i, r)
rad.sort()
print(rad[10**4][1])
for _ in range(int(input())):
    ttt, lll = map(int, input().split())
    mimi = 0
    for ra in rad:
        if ra[1] <= ttt:
            if mimi == lll:
                print(ra[1])
                break
            mimi += 1
