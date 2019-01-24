def gcdp(a, b):
    if b == 0:
        return a
    else:
        return gcdp(b, a % b)


def relapri(a, b):
    return gcdp(a, b) == 1


ax, bx = map(int, input().split())
res = 0
for i in range(bx+1):
    a = (i//(ax+1))+1
    b = (i//ax)
    if i % ax == 0:
        b -= 1
    for j in range(a, b+1):
        if relapri(j, i):
            res += 1
print(res)
