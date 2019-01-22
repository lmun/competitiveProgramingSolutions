for t in range(int(input())):
	ware = {}
	for w in range(int(input())):
		a, b = input().split()
		b=int(b)
		ware[a] = ware.get(a, 0) + b
	print(len(ware))
	res = list(ware.items())
	res.sort()
	res.sort(key=lambda x:x[1], reverse=True)
	for r1, r2 in res:
		print(r1,r2)