a = list()
lar = int(input())
for i in range(lar):
    a.append([int(x) for x in input().split()])
    # print(len(a[i]))


def sususu(i, j):
    if i == 0:
        if j == 0:
            return
        else:
            a[i][j] += a[i][j-1]
            return
    if j == 0:
        a[i][j] += a[i-1][j]
        return
    else:
        a[i][j] += min(a[i-1][j], a[i][j-1])
        return


mama = [[0]*lar for _ in range(lar)]
coco = 0
lau = lar-1
lad = lar-2
for i in range(lar):
    for j in range(i+1):
        sususu(i-j, j)
        mama[i-j][j] += 1
        if mama[i-j][j] > 1:
            print(i-j, j)
        coco += 1
for i in range(lad, -1, -1):
    for j in range(i+1):
        sususu(lau-j, lau-i+j)
        mama[lau-j][lau-i+j] += 1
        if mama[lau-j][lau-i+j] > 1:
            print(lau-j, lau-i+j)
        coco += 1
print(a[lau][lau])

# for i in range(80):
# print(', '.join(map(str, a[0])))
