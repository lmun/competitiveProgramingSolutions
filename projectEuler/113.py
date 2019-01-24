li = 10**5
ttd = [0]*li
tti = [0]*li
inc = [1]*10
dec = [1]*10
bot = [1]*10
inc[0] = 0
dec[0] = 0
eq = 9*li
mod = 10**9+7
toti = sum(inc)
for jj in range(1, li):
    acc = 0
    for i in range(10):
        acc += inc[i]
        # print(i, inc[i])
        inc[i] = acc
    toti += sum(inc)
    tti[jj] = toti
totd = sum(dec)
for jj in range(1, li):
    acc = 0
    for i in reversed(range(10)):
        acc += dec[i]
        dec[i] = acc
    totd += sum(dec)
    ttd[jj] = totd
# print(toti, totd, eq)
# print(totd+toti-eq)
for _ in range(int(input())):
    wa = int(input())
    print((ttd[wa-1]+tti[wa-1]-9*wa) % mod)
