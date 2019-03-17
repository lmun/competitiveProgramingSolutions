try:
	t = 1
	while True:
		n, d = map(int, input().split())
		if n == 0 and d == 0:
			break
		isl = [tuple(map(int, input().split())) for _ in range(n)]
		isl.sort()
		d2 = d*d
		priant = isl[0][0]
		antpos = isl[0][0]
		while (antpos+1-isl[0][0])**2 + isl[0][1]**2 <= d2:
			antpos += 1
		ants = 1
		# print(antpos)
		for xi, yi in isl:
			if yi > d:
				ants = -1
				break
			while (antpos-xi)**2+yi**2 > d2:
				antpos -= 1
				if antpos < xi:
					ants += 1
					antpos = xi
					while (antpos+1-xi)**2 + yi**2 <= d2:
						antpos += 1
		print("Case {}: {}".format(t, ants))
		# print(priant, isl)
		input()
		t += 1
except Exception as e:
	pass