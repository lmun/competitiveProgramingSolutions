n, m = map(int, input().split())
verli = []
uf = [i for i in range(n)]
tam = [1]*n
dif = [0]*m
G = [[] for _ in range(n)]


def getrep(nu):
    if uf[nu] == uf[uf[nu]]:
        return uf[nu]
    r = getrep(uf[nu])
    uf[nu] = r
    return uf[nu]


def maxdis(visi, a, b, c):
    # print(a, b, c)
    visi[a] = True
    co = c
    for x, y in G[a]:
        if x == b:
            co = max(c, y)
            break
        elif not visi[x]:
            visi[x] = True
            # print(a, x)
            e = maxdis(visi, x, b, max(c, y))
            if e > 0:
                # print("wata", e, c)
                co = e
                break
    else:
        # print(a, b, c)
        return -1
    return co


for j in range(m):
    a, b, c = map(int, input().split())
    verli.append((c, a-1, b-1, j))
verliso = sorted(verli)
total = 0
for c, a, b, o in verliso:
    ra = getrep(a)
    rb = getrep(b)
    if ra != rb:
        if tam[ra] < tam[rb]:
            ra, rb = rb, ra
        uf[rb] = uf[ra]
        tam[ra] += tam[rb]
        # print(tam[a], o, a, b, tam[a], tam[b])
        total += c
        G[a].append((b, c))
        G[b].append((a, c))
    else:
        visi = [False]*n
        dif[o] = c-maxdis(visi, a, b, 0)
        # print(a, b, c, c-dif[o], o, '-')

for d in dif:
    print(total+d)
# print(total)
