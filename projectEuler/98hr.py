from sys import stdin

cubos = list()
pril = [0]*20
todo = {}
for i in range(1000000001):
    n = i*i
    p = str(n)
    if pril[len(p)] == 0:
        pril[len(p)] = i
    # print(''.join(sorted(list(p))))
    x = ''.join(sorted(list(p)))
    if x not in todo:
        todo[x] = 1
    else:
        # a, b = todo[x]
        todo[x] += 1
        # print(x, todo[x])
    # print(p)
    cubos.append(p)
    if n > 10**14:
        break
for t in range(1, 20):
    if pril[t] == 0:
        break
    mcub = ""
    mxx = 0
    for xx in range(pril[t-1], pril[t]):
        stenum = todo[''.join(sorted(list(cubos[xx])))]
        if stenum >= mxx:
            mxx = stenum
            mcub = cubos[xx]
            # print(mxx, mcub)
            # print(todo[''.join(sorted(list(cubos[xx])))])
    print(mcub)
