m = 1000
mat = [[0]*m for _ in range(m)]
mat[1][0] = mat[1][1] = 1
for i in range(2, m):
    for j in range(i):
        mat[i][j] = mat[i-1][j]*i
    for j in range(1, i+1):
        mat[i][j] += mat[i-1][j-1]
    a = sum(mat[i][j] for j in range(i//2+1, i+1))
    b = sum(mat[i][j] for j in range(i+1))
    print(i, a, b)
