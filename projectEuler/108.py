li = 100000
cri = [0]*li
pri = []
for i in range(2, li):
    if cri[i] == 0:
        cri[i] = i
        pri.append(i)
        for j in range(i*i, li, i):
            cri[j] = i

minu = 10**100


def dfs(p, n, c, l, nu):
    global minu
    a = (n*(2*c+1))//2+1
    if a > 4*10**6 and nu < minu:
        print(a, nu)
        minu = nu
    if l < 0:
        return
    dfs(p+1, n*(2*c+1), 1, l-1, nu*pri[p+1])
    dfs(p, n, c+1, l-1, nu*pri[p])


dfs(0, 1, 1, 20, 2)
