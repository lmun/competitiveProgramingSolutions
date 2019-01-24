while True:
	s, b = map(int, input().split())
	if s == 0 and b == 0:
		break
	izq = [i for i in range(s)]
	der = [i+2 for i in range(s)]
	izq[0] = "*"
	der[s-1] = "*"
	for _ in range(b):
		l, r = map(lambda x: int(x)-1, input().split())
		le = izq[l]
		ri = der[r]
		if le != "*":
			der[le-1] = ri
		if ri != "*":
			izq[ri-1] = le
		print(le,ri)
	print("-")
