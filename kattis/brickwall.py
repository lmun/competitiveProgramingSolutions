while True:
	try:
		lars = [int(x) for x in input().split()]
		la = set(lars[1:])
		visi = set()
		wall = list(map(int, input().split()))
		largo = [lars[x] for x in wall]
		tot = 0
		se = set()
		for l in largo:
			tot += l
			se.add(tot)
		posi = False
		print(se)
		while la:
			n = la.pop()
			if n in visi:
				continue
			else:
				visi.add(n)
			if n == tot:
				posi = True
				break
			if n not in se:
				for a in lars[1:]:
					if n + a <= tot:
						la.add(n + a)
		print('yes' if posi else 'no')
	except Exception as e:
		print(e)
		break