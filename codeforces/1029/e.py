tot = 0
def dfsx(a, b):
    global tot, visi
    if visi[a]:
        return
    visi[a] = True
    if (b == 2 and len(mat[a]) > 1) or b > 2:
        b = 1
        tot += 1
        # print('waa')
    if len(mat[a]) > 1:
        for x in mat[a]:
            dfsx(x, b+1)


n = int(input())
mat = [[] for _ in range(n)]
visi = [False]*n
visi[0] = True
for _ in range(n-1):
    a, b = map(int, input().split())
    mat[a-1].append(b-1)
    mat[b-1].append(a-1)
for x in mat[0]:
    dfsx(x, 1)
print(tot)
