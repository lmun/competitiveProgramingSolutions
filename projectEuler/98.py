from sys import stdin
list("hola")
cubos = list()
pril = [0]*20

for i in range(1000000001):
    n = i*i
    p = str(n)
    if pril[len(p)] == 0:
        pril[len(p)] = i
        print()
    # print(p)
    cubos.append(p)
    if n > 10**10:
        break
print("cuadrados listos")
todo = {}
ma = 12
ml = 0
maxi = 0
for line in stdin:
    estaw = line.strip()
    """if len(set(line))>ml:
        ml=len(set(estaw))
        for x in set(estaw):
            print(x)
        print('--',estaw)"""
    estapl = list(estaw)
    if len(estaw) == 7:
        print(estaw)
        ma = len(estaw)
        for c in line.strip():
            # print(c,ord(c)-65)
            pass
        for i in range(pril[len(estaw)], pril[len(estaw)+1]):
            # print(i)
            estec = ['.']*26
            nunu = [False]*10
            for j in range(len(estapl)):
                if nunu[int(cubos[i][j])]:
                    if estec[ord(estaw[j])-65] != cubos[i][j]:
                        # print("nononono")
                        break
                else:
                    if estec[ord(estaw[j])-65] == '.':
                        estec[ord(estaw[j])-65] = cubos[i][j]
                        nunu[int(cubos[i][j])] = True
                    elif estec[ord(estaw[j])-65] != cubos[i][j]:
                        break
            else:
                # print(estaw,"sisisisisi")
                # print(cubos[i])
                jach = ''.join(estec)
                if jach in todo:
                    print("pali", todo[jach], int(cubos[i]))
                    todo[jach] = max(todo[jach], int(cubos[i]))
                    if todo[jach] > maxi:
                        print(todo[jach])
                        maxi = todo[jach]
                else:
                    todo[jach] = int(cubos[i])
            # print(estaw)
            # print(cubos[i],''.join(estec))
for i in todo:
    # print(i,todo[i])
    pass
print(len(cubos))
for i in range(20):
    print(i, pril[i], cubos[pril[i]])
    pass
print('ml', ml)
print(maxi)
