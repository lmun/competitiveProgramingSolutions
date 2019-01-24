li = 100000
cri = [0]*li
pri = []
for i in range(2, li):
    if cri[i] == 0:
        cri[i] = i
        pri.append(i)
        for j in range(i*i, li, i):
            cri[j] = i

minu = 10**1000
# limi = int(input())
limi = 4*10**10


def dfs(p, n, c, l, nu):
    global minu
    a = (n*(2*c+1))//2+1
    if a >= limi and nu < minu:
        # print(a, nu)
        minu = nu
    if l < 0:
        return
    if nu*pri[p] < minu:
        dfs(p, n, c+1, l-1, nu*pri[p])
    if nu*pri[p+1] < minu:
        dfs(p+1, n*(2*c+1), 1, l-1, nu*pri[p+1])


dfs(0, 1, 1, 22, 2)
print(minu)
