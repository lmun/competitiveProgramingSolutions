def todos(a, b, c):
    global m
    if c == 0:
        return
    wa = (a+c)*(b+c)-c*c
    todos(a, b, c-1)
    if b == c:
        todos(a, b-1, c-1)
    if wa < 10*m:
        r[wa] += 1
    return wa


m = 200
r = [0]*(m*10)
te = 0
for i in range(1, 100):
    te = max(te, todos(i, i, i))
mama = 0
for j in range(len(r)):
    if r[j] > mama:
        print(j, r[j])
        mama = r[j]
