x = 8000
cri = [0]*x
pri = list()
for i in range(2, x):
    if cri[i] == 0:
        cri[i] = i
        pri.append(i)
        for j in range(i*i, x, i):
            cri[j] = i
limi = 2*10**7+1
total = 0
nums = set()


def cuenta(a, b, c, d):
    global total
    e = pri[a]**2+pri[b]**3+pri[c]**4
    if e < limi:
        total += 1
        nums.add(e)
    else:
        return
    cuenta(a, b, c+1, 2)
    if d == 2:
        return
    cuenta(a, b+1, c, 1)
    if d == 1:
        return
    cuenta(a+1, b, c, 0)


cuenta(0, 0, 0, 0)
wata = list(sorted(nums))
# print(total, len(nums), len(wata))

for _ in range(int(input())):
    limi = int(input())
    if limi < 28:
        print(0)
        continue
    lo, hi = 0, len(wata)-1
    while hi > lo:
        mi = (hi+lo+1)//2
        if wata[mi] > limi:
            hi = mi-1
        else:
            lo = mi
    print(lo+1)
