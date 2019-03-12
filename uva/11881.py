def aux(nu):
	res = 0
	for v in vals:
		res *= nu
		res += v
	return res/(nu**(n))
while True:
	n = int(input())
	if n == 0:
		break
	vals = [int(x) for x in input().split()]
	lo, hi = 1, 1
	if aux(1) < 0:
		while aux(lo) < 0:
			lo /= 2
	else:
		while aux(hi) >= 0:
			hi *= 2
	for _ in range(20):
		mid = (hi+lo)/2
		if aux(mid) > 0:
			lo = mid
		else:
			hi = mid
	print("{:.2f}".format(hi-1))
