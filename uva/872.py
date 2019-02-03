def dfs(a, b, c, d):
    # print(a, b, c, d)
    global isposi
    if len(c) == d:
        print(" ".join(c))
        isposi = True
    for y in range(len(b)):
        if b[y] == 0 and vals[y] not in c:
            esta = list(b)
            for p in mat[y]:
                esta[p] -= 1
            g = list(c)
            g.append(vals[y])
            dfs(y, esta, g, d)


t = int(input())
isposi = False
for i in range(t):
    if i > 0:
        print()
    input()
    isposi = False
    vals = list(input().split())
    rest = list(input().split())
    vals.sort()
    inci = [0]*len(vals)
    m = {}
    j = 0
    for v in vals:
        m[v] = j
        j += 1
    mat = [[] for _ in range(j)]
    for r in rest:
        mat[m[r[0]]].append(m[r[-1]])
        inci[m[r[-1]]] += 1
    for tt in range(len(mat)):
        if inci[tt] == 0:
            esta = list(inci)
            for y in mat[tt]:
                esta[y] -= 1
            dfs(tt, esta, [vals[tt]], j)
    if not isposi:
        print("NO")
