from itertools import product, permutations, combinations
n = int(input())
names = {}
nex = 0
mama = 128
liking = [0]*mama
likes = [[0]*7 for _ in range(7)]


def getName(name):
    global nex
    if name in names:
        return names[name]
    names[name] = nex
    nex += 1
    return names[name]


for _ in range(n):
    a, b, c = input().split()
    likes[getName(a)][getName(c)] = 1
bosses = [int(x) for x in input().split()]


part = set()
part.add((0, 0, 0))
dipart = 10**10
for i in range(1, 4):
    for j in range(i, 7):
        k = 7-i-j
        if k < j:
            continue
        for per in permutations(bosses):
            aa = (per[0]//i, per[1]//j, per[2]//k)
            difi = max(aa)-min(aa)
            if difi < dipart:
                dipart = difi
                part = set()
                part.add((i, j, k))
            elif difi == dipart:
                part.add((i, j, k))
# print(part, dipart)
# print(a,b,c)
for i, j in product(range(7), repeat=2):
    if likes[i][j] == 0:
        continue
    mask = (1 << i) | (1 << j)
    for k in range(mama):
        if k & mask == mask:
            liking[k] += 1
nums = list(range(7))


def tonum(ite):
    r = 0
    for nu in ite:
        r |= 1 << nu
    return r


bea = 0
# print(part)
for a, b, c in part:
    for pera in combinations(range(7), a):
        # print(pera)
        lefta = [x for x in nums if x not in pera]
        for perb in combinations(lefta, b):
            perc = [x for x in lefta if x not in perb]
            # print(pera, perb, perc)
            # print(tonum(pera), tonum(perb), tonum(perc))
            susu = liking[tonum(pera)] + liking[tonum(perb)
                                                ] + liking[tonum(perc)]
            if susu > bea:
                bea = susu
                # print(liking[tonum(pera)],
                #     liking[tonum(perb)] , liking[tonum(perc)])
print(dipart, bea)
# for i in range(mama):
#     print(i, liking[i])
