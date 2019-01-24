mp = 1000000
m = 1010
dp = [[-1]*m for _ in range(m)]
pri = list()
cri = [0]*mp
for i in range(2, mp):
    if cri[i] == 0:
        cri[i] = i
        pri.append(i)
        for j in range(i*i, mp, i):
            cri[j] = i


def ways(n, t):
    if dp[n][t] >= 0:
        return dp[n][t]
    if n < 2:
        return 0
    if pri[t] > n:
        return 0
    tot = 0
    if n in pri:
        tot += 1
    for i in range(t, n):
        if n >= 2*pri[i]:
            tot += ways(n-pri[i], i)
        else:
            break
    # print(n, t, tot)
    dp[n][t] = tot
    return dp[n][t]


"""
for i in range(2, m):
    if ways(i, 0) > 5000:
        print(i)
        break
"""
for _ in range(int(input)):
    print(ways(int(input()), 0))
