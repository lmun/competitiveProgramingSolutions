limi = int(input())
a = list()
for i in range(limi):
    a.append([int(x) for x in input().split()])
    # print(len(a[i]))


def sususu(i, j):
    po = mama[i][j-1]
    t = 0
    for pi in range(i+1, limi):
        t += a[pi][j]
        po = min(po, t+mama[pi][j-1])
    t = 0
    for pi in range(i-1, -1, -1):
        t += a[pi][j]
        po = min(po, t+mama[pi][j-1])
    mama[i][j] = po+a[i][j]


mama = [[0]*limi for _ in range(limi)]
coco = 0
for i in range(limi):
    mama[i][0] = a[i][0]
"""
for i in range(limi):
    print(', '.join(map(str, mama[i])))
"""
for i in range(1, limi):
    for j in range(limi):
        sususu(j, i)
        coco += 1
res = 100000000000000000
for i in range(limi):
    res = min(res, mama[i][limi-1])
print(res)
# print(a[79][79],coco)

# for i in range(limi):
    # print(', '.join(map(str, mama[i])))
