m = 10**8
cri = [0]*m
pri = []
for i in range(2, m):
    if cri[i] == 0:
        cri[i] = i
        pri.append(i)
        for j in range(i*i, m, i):
            cri[j] = i
print(len(pri))
lim = 10**8
res = 0
for i in reversed(range(len(pri))):
    l = 0
    h = i
    while h > l:
        mid = (h+l+1)//2
        if pri[mid]*pri[i] > lim:
            h = mid - 1
        else:
            l = mid
    if pri[i] * pri[l] <= lim:
        res += l+1
print(res)
