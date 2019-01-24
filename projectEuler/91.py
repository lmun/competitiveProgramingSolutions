def pitaeh(p1, p2, p3):
    global b
    x = (p2//b)**2+(p2 % b)**2
    y = (p3//b)**2+(p3 % b)**2
    z = (p2//b-p3//b)**2+(p2 % b-p3 % b)**2
    if x > y:
        x, y = y, x
    if y > z:
        z, y = y, z
    if x > y:
        x, y = y, x
    # print(x,y,z)
    return 0 < x and y < z and x+y == z


b = int(input())+1


res = 0
for i in range(b, b*b):
    for j in range(1, i):
        if pitaeh(0, i, j):
            res = res+1
            # print(i//b,i%b,j//b,j%b)
print(res)


# print(pitaeh(0,4,2))
