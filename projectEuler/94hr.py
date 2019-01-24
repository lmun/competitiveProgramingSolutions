for _ in range(int(input())):
    res94 = 0
    m = 10**int(input())
    a, b, c = 1, 2, 4
    while True:
        l1 = 4*(b*b)
        l2 = 2*(a+c)**2
        # print(l1, l2)
        if l1 <= m:
            res94 += l1
        if l2 <= m:
            res94 += l2
        if l1 > m and l2 > m:
            break
        print(a**2+b**2, 2*(b**2-a**2), l1)
        print(a**2+c**2, 4*a*c, l2)
        a, b, c = c, a+b+c, a+b+3*c
    print(res94)
