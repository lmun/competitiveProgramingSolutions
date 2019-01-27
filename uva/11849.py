while True:
	n, m = map(int, input().split())
	if n == 0 and m == 0:
		break
	nn = [int(input()) for _ in range(n)]
	mm = [int(input()) for _ in range(m)]
	a = 0
	b = 0
	res = 0
	while(a < n and b < m):
		if nn[a] == mm[b]:
			res += 1
			a += 1
			b += 1
		elif nn[a] < mm[b]:
			a += 1
		else:
			b += 1
	print(res)
