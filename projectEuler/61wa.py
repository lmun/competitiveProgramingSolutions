from math import sqrt


def poliTest(p, n):
    a = (n-4)*(n-4)+8*p*(n-2)
    b = int(sqrt(a))
    if a != b*b:
        return False
    if n == 2:
        return True
    c = b+n-4
    d = 2*(n-2)
    return c % d == 0


def busca(n, d, s, ori, kk):
    if d == 0:
        # print(n,ori,n)
        return n == ori
    # print(n)
    for i in range(10, 100):
        for j in range(3, 9):
            if j not in s and j in nums and poliTest(100*n+i, j) and 100*n+i not in kk:
                mis = set(s)
                mis.add(j)
                mik = set(kk)
                mik.add(100*n+i)
                # print(100*n+i,j)
                we = busca(i, d-1, mis, ori, mik)
                if we > 0:
                    # print(j,100*n+i)
                    return we+100*n+i
    return 0


def poli(s, n):
    return (n*n*(s-2)-n*(s-4))//2


n = int(input())
nums = list(map(int, input().split()))
i = 0
res = list()
while True:
    i += 1
    pol = poli(nums[-1], i)
    if pol < 1000:
        continue
    if pol > 9999:
        break
    s = set()
    s.add(nums[-1])
    kk = set()
    kk.add(pol)
    if pol % 100 > 9:
        we = busca(pol % 100, n-1, s, pol//100, kk)
        if we > 0:
            res.append(we+pol-1)
res.sort()
for r in res:
    print(r)
