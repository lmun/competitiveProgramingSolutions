from itertools import combinations

def fun(vals):
	res = 0
	ex = set()
	for n in vals:
		res += tow[n]
		ex |= pert[n]
	for n in ex:
		res += extra[n]
	return res
test = 0
while True:
	try:
		test += 1
		p, b = map(int, input().split())
		if p == b and b==0:
			break
		tow = [int(x) for x in input().split()]
		mat = [[0]*p for _ in range(p)]
		m = int(input())
		extra = [0]*m
		pert = [set() for _ in range(p)]
		for kk in range(m):
			noo = [int(x)-1 for x in input().split()]
			sii = noo[1:-1]
			extra[kk] = noo[-1]+1
			for n in sii:
				pert[n].add(kk)
				tow[n] -= extra[kk]
		best = []
		mama = 0
		for com in combinations(range(p), b):
			este = fun(com)
			if este > mama:
				mama = este
				best = com
		print("Case Number  {}".format(test))
		print("Number of Customers: {}".format(mama))
		print("Locations recommended: {}".format(' '.join(map(lambda x:str(x+1), best))))
		print()
	except Exception as e:
#		print(e)
		break
