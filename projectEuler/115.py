for _ in range(int(input())):
    b = [1]
    r = [0]
    a = [1]
    x, m = map(int, input().split(' '))
    for i in range(1, x):
        r.append(0)
        b.append(1)
        a.append(a[-1]+1)
    t = x
    while True:
        b.append(r[-1]+b[-1])
        r.append(a[-x])
        a.append(a[-1]+b[-1])
        if b[-1] + r[-1] > m:
            print(t)
            break
        t += 1
