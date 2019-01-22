res = [[0,0,3,3],
		[0,0,0,3],
		[1,0,0,0],
		[1,1,0,0]]

def ori(x, y):
	h = max(x, y)
	d = 1
	while h // d > 3:
		d *= 2
	a = x//d
	b = y//d
	ro = res[b][a]
	di = 0
	if d > 1:
		if ro == 1:
			di = ori(d*4-1-y, x)
		elif ro == 3:
			di = ori(y, d*4-1-x)
		else:
			miab = min(a,b)
			di = ori(x - miab*d, y - miab*d)
		return (ro + di) % 4
	else:
		return ro

def nini(n):
	if n < 1:
		return '/'
	elif n < 2:
		return '|'
	elif n < 3:
		return '-'
	return '\\'
#for t in range(int(input())):
#	x, y = map(int, input().split())
#	print(ori(x, y))
pp = 6
aaa = [[nini(ori(i,j)) for i in range(2**pp)] for j in reversed(range(2**pp))]
for a in aaa:
   print(''.join(a))