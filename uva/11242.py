from itertools import product
while True:
	try:
		f, r = map(int, input().split())
		ff = [int(x) for x in input().split()]
		rr = [int(x) for x in input().split()]
		ratios = list(map(lambda x: x[0] / x[1], product(ff, rr)))
		ratios.sort()
		madi = 0
		#print(ratios)
		for i in range(1, len(ratios)):
			madi = max(madi, ratios[i]/ratios[i-1])
		print("{:.2f}".format(madi))
	except Exception as e:
		#print(e)
		break
