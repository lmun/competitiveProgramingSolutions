from heapq import heappop, heappush
# spoj NWERC11E
for t in range(int(input())):
	n = int(input())
	pala = input().strip()
	ultis = {}
	total = {}
	h = []
	for a, c in enumerate(pala):
		ultis[c] = a
		total[c] = total.get(c, 0) + 1
	totini = 0
	espe = 0
	for a, c in enumerate(pala):
		totini += espe
		if a != ultis[c]:
			espe += 1
		else:
			espe -= (total[c]-1)
	for ind, ite in ultis.items():
		heappush(h, (ite, ind))
	totfin = 0
	while h:
		a, b = heappop(h)
		x = total[b]
		totfin += (x*x-x)//2
	print(5*(totini - totfin))
	