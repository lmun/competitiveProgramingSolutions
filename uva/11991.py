while True:
	try:
		n, m = map(int, input().split())
		mat = {}
		nums = [int(x) for x in input().split()]
		for wa in range(len(nums)):
			#print(mat.get(nums[wa], []))
			mat[nums[wa]] = mat.get(nums[wa], []) + [wa + 1]
			#print(mat[nums[wa]])
		for q in range(m):
			k, v = map(int, input().split())
			if v in mat and len(mat[v]) >= k:
				print(mat[v][k-1])
			else:
				print(0)
	except Exception as e:
		#print(e)
		break
