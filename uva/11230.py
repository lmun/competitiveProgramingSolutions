from itertools import product
while True:
	n, m, r, c = map(int, input().split())
	if n == 0:
		break
	mat = [int(input(), 2) for _ in range(n)]
	res = 0
	dc = (1<<c)-1
	for i, j in product(range(n-r+1), range(m-c+1)):
		if (mat[i]>>j)&1:
			for x in range(r):
				mat[i+x]^= dc<<j
			res += 1
	for i in range(n):
		if mat[i]:
			print(-1)
			break
	else:
		print(res)
