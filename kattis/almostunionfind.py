# also uva 11987 but it's a TLE in uva
while True:
    try:
        n, m = map(int, input().split())
        rep = [i for i in range(n)]
        sets = [set() for i in range(n)]
        suma = [i for i in range(n)]
        for i in range(n):
            sets[i].add(i)
        for i in range(m):
            li = list(map(int, input().split()))
            if li[0] == 1:
                ra = rep[li[1]-1]
                rb = rep[li[2]-1]
                if(ra != rb):
                    if len(sets[ra]) > len(sets[rb]):
                        sets[ra] |= sets[rb]
                        suma[ra] += suma[rb]
                        for n in sets[rb]:
                            rep[n] = ra
                    else:
                        sets[rb] |= sets[ra]
                        suma[rb] += suma[ra]
                        for n in sets[ra]:
                            rep[n] = rb
            elif li[0] == 2:
                a = li[1]-1
                b = li[2]-1
                sets[rep[a]].remove(a)
                suma[rep[a]] -= a
                rep[a] = rep[b]
                sets[rep[a]].add(a)
                suma[rep[a]] += a
            else:
                x = rep[li[1]-1]
                print(len(sets[x]), len(sets[x]) + suma[x])
    except Exception as e:
        break
