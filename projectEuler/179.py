m = 10**7
cri = [1]*m
resp = [0]*m
for i in range(2, m):
    for j in range(i, m, i):
        cri[j] += 1
res = 0
for i in range(3, m):
    if cri[i] == cri[i-1]:
        res += 1
    resp[i] = res
for i in range(int(input())):
    print(resp[int(input())])
