best = []
visi = set()
def fs(a, b):
	#print(a,b)
	global best
	if (a,b) in visi:
		return
	visi.add((a, b))
	if a == 0:
		#print('b',b)
		res = [i+1 for i in range(n) if b&(1<<i)]
		if len(res) > len(best):
			best = res
		#print(res)
	for i in range(n):
		if (1<<i) & a:
			na = a
			for j in mat[i]:
				na = na & ~(1<<j)
			fs(na, b | (1<<i))
for t in range(int(input())):
	n, k = map(int, input().split())
	mat = [[i] for i in range(n)]
	for i in range(k):
		x, y = map(lambda x:int(x)-1, input().split())
		mat[x].append(y)
		mat[y].append(x)
	avali = (1<<n) - 1
	black = 0
	best = []
	visi = set()
	fs(avali, black)
	print(len(best))
	print(' '.join(map(str, best)))
