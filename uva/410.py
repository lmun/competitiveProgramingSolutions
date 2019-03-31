try:
	se = 1
	while True:
		c, s = map(int, input().split())
		ma = [int(x) for x in input().split()]+[0]*(2*c-s)
		ma.sort()
		res = [[] for _ in range(c)]
		for i in range(c):
			if ma[i]:
				res[i].append(ma[i])
		for i in range(c):
			if ma[i+c]:
				res[-1-i].append(ma[i+c])
		print("Set #{}".format(se))
		for i,v in enumerate(res):
			print(" {}:".format(i), end='')
			if len(v):
				print(" {}".format(" ".join(map(str, v))), end='')
			print()
		pro = sum(ma)/c
		print("IMBALANCE = {:.5f}".format(sum(abs(sum(x)-pro) for x in res)))
		print()
		se += 1
except Exception as e:
	# print(e)
	pass