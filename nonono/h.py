caso = 0
while True:
	try:
		caso += 1
		n, p = map(int, input().split())
		if n == 0:
			break
		req = [input().strip() for _ in range(n)]
		mejor = None
		mc = 10**20
		mr = 0
		for pro in range(p):
			name = input().strip()
			c, t = input().split()
			c = float(c)
			t = int(t)
			met = [input().strip() for _ in range(t)]
			if t > mr or (t == mr and c < mc):
				mejor = name
				mc = c
				mr = t
		if caso > 1:
			print()
		print("RFP #{}".format(caso))
		print(mejor)
	except Exception as e:
		raise
	else:
		pass
	finally:
		pass