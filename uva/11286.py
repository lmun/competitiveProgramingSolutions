while True:
    n = int(input())
    if n == 0:
        break
    mapa = {}
    for i in range(n):
        cur = ''.join(sorted(input().split()))
        mapa[cur] = mapa.get(cur, 0) + 1
    maxa = max(mapa.values())
    res = 0
    for a, b in mapa.items():
        if b == maxa:
            res += b
    print(res)
