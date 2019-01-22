for t in range(int(input())):
	s, h = map(int, input().split())
	hat = [tuple(map(int, input().split())) for _ in range(h)]
	listo = False
	res = 'poodle'
	for a in range(1, s):
		if listo:
			break
		for b in range(1, s):
			if listo:
				break
			if (a, b) in hat:
				continue
			edge = min(a, s-a, b, s-b)
			edcua = edge * edge
			for hx, hy in hat:
				if edcua < (a-hx)*(a-hx)+(b-hy)*(b-hy):
					break
			else:
				res = '{} {}'.format(a, b)
				listo = True
	print(res)