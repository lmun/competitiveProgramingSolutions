k = int(input())
t = 10**k
dp = [0]*max(10000000, t)


def scuadi(n):
    if dp[n] > 0:
        return dp[n]
    r = 0
    for c in str(n):
        cd = int(c)
        r += cd*cd
    if r == 1 or r == 89:
        dp[n] == r
        return r
    # print(n,r)
    dp[n] = scuadi(r)
    return dp[n]


res = 0
for i in range(1, t):
    wa = scuadi(i)
    # print(i,wa)
    if wa == 89:
        res += 1
print(res)
