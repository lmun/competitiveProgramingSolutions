for _ in range(int(input())):
    dif = 1001
    clo = 0
    lar = 0
    t = int(input())
    for i in range(1, 2001):
        f = (i*(i+1))//2
        for j in range(i, 2001):
            p = (j*(j+1))//2
            n = p*f
            if abs(n-t) <= dif:
                dif = abs(n-t)
                clo = n
                lar = i*j
                # print(i, j, n, dif)
            if n > t:
                break
    print(lar)
