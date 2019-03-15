for t in range(int(input())):
	n, d = map(int, input().split())
	stones = list(input().split())
	pos = [d, d]
	for st in stones:
		nu = int(st[2:])
		pos.append(nu)
		if st[0] == 'B':
			pos.append(nu)
	pos.sort()
	a, b = 0, 0
	madi = 0
	for p in pos:
		if p > madi + a:
			madi = p-a
		a, b = b, p
	print("Case {}: {}".format(t+1, madi))
