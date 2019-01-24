m = 10**6
cri = [0]*m
pri = []
for i in range(2, m):
    if cri[i] == 0:
        cri[i] = i
        pri.append(i)
        for j in range(i*i, m, i):
            cri[j] = i
se = set()
for i in range(m):
    se.add(i*i*i)
for p in pri:
    for j in range(1, 10**6):
        if j*j*(j+p) in se:
            print(j, p, j*j*(j+p))
