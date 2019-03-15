def posi(ii, ff ,l, bm):
	res = False
	if l == 0:
		return ii == ff
	for i in range(m):
		if 1<<i & bm:
			if vals[i][0] == ii:
				res = res or posi(vals[i][1], ff, l-1, bm & ~(1<<i))
			elif vals[i][1] == ii:
				res = res or posi(vals[i][0], ff, l-1, bm & ~(1<<i))
	return res
while True:
	try:
		n = int(input())
		m = int(input())
		ini = tuple(map(int, input().split()))
		fin = tuple(map(int, input().split()))
		vals = [tuple(map(int, input().split())) for _ in range(m)]
		print("YES" if posi(ini[1], fin[0], n, (1<<m) - 1) else "NO")
	except Exception as e:
		#print(e)
		break
