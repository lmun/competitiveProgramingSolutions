while True:
	try:
		m, n = map(int, input().split())
		mat = [[] for _ in range(n)]
		for t in range(m):
			pos = list(map(int, input().split()))
			nums = list(map(int, input().split()))
			for i in range(1, len(pos)):
				mat[pos[i] - 1].append((t, nums[i - 1]))
		print(n, m)
		for col in mat:
			# soso = mat.sort()
			if col:
				print(len(col), ' '.join(map(lambda x:str(x[0] + 1), col)))
			else:
				print(0)
			print(' '.join(map(lambda x:str(x[1]), col)))
	except Exception as e:
		#print(e)
		break