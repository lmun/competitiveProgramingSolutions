for t in range(int(input())):
	d, i = map(int, input().split())
	r = 0
	i -= 1
	for _ in range(d-1):
		r <<= 1
		if i & 1:
			r += 1
		i >>= 1
	print(r + (1<<(d-1)))