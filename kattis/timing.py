for t in range(int(input())):
	n, l, t = map(int, input().split())
	forstr = list(map(int, input().split()))
	links = []
	for _ in range(l):
		a, b, c = input().split()
		links.append((int(a), int(b), float(c)))
	for _ in range(t):
		nextl = list(forstr)
		for a, b, c in links:
			dif = forstr[a] * c
			nextl[b] += dif
			nextl[a] -= dif
#		print(1, forstr)
#		print(2, nextl)
		forstr = nextl
	maxcap = list(forstr)
	for a, b, c in links:
		maxcap[b] += forstr[a]
		maxcap[a] += forstr[b]
#	print(forstr)
#	print(maxcap)
	print(min(maxcap))
