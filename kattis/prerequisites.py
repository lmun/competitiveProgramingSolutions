while True:
	try:
		k, m = map(int, input().split())
		cursos = set(map(int, input().split()))
		posi = True
		for i in range(m):
			cate = list(map(int, input().split()))
			tot = 0
			for c in cate[2:]:
				# print(c)
				if c in cursos:
					tot += 1
			if tot < cate[1]:
				# print(cate, tot)
				# print('no')
				posi = False
		if not posi:
			print('no')
		else:
			print('yes')
	except Exception as e:
		# print(e)
		break
