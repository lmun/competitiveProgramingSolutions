from math import log
i = 0
m = 0.0
mat = []
for _ in range(int(input())):
    i += 1
    b, e = input().strip().split()
    es = float(e)*log(int(b))
    mat.append((es, b, e))
    # print(b*log(int(e)),i)
mat.sort()
nu = int(input())-1
print(mat[nu][1], mat[nu][2])
