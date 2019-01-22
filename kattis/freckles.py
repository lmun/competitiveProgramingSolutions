from math import sqrt
def difi(a, b):
	dx = a[0]-b[0]
	dy = a[1]-b[1]
	return sqrt(dx*dx + dy*dy)

def getrep(a):
	if rep[a] == a:
		return a
	else:
		rep[a] = getrep(rep[a])
		return rep[a]


for t in range(int(input())):
	input()
	m = int(input())
	poin = [tuple(map(float, input().split())) for _ in range(m)]
	ari = []
	for i in range(m):
		for j in range(i):
			ari.append((difi(poin[i], poin[j]), i, j))
	ari.sort()
	# print(ari)
	rep = [i for i in range(m)]
	sis = [1] * m
	tot = 0
	for n in ari:
		rex = getrep(n[1])
		rey = getrep(n[2])
		if rex != rey:
			tot += n[0]
			if sis[rex] > sis[rey]:
				rep[rey] = rex
				sis[rex] += sis[rey]
			else:
				rep[rex] = rey
				sis[rey] += sis[rex]
	print("{0:.2f}".format(tot))


