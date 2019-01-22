def dfs(n, a, b, c):
	if (n, a, b, c) in visi:
		return False
	if n == tot:
		return True
	if n in se:
		return False
	if n > tot:
		return False
	visi.add((n, a, b, c))
	if a > 0 and dfs(n+1, a-1, b, c):
		return True
	elif b > 0 and dfs(n+2, a, b-1, c):
		return True
	elif c > 0 and dfs(n+3, a, b, c-1):
		return True
	return False



while True:
	try:
		lars = [int(x) for x in input().split()]
		visi = set()
		largo = list(map(int, input().split()))
		tot = 0
		se = set()
		for l in largo:
			tot += l
			se.add(tot)
		posi = False
		#print(se)
		print('YES' if dfs(0, lars[1], lars[2], lars[3]) else 'NO')
	except Exception as e:
		break