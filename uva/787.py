try:
	while True:
		nums = [int(x) for x in input().split()]
		while nums[-1] != -999999:
			nums.extend(int(x) for x in input().split())
		nums.pop()
		ln = len(nums)
		nr = [0]*ln
		pr = [0]*ln
		pr[0] = nums[0]
		nr[0] = nums[0]
		for i,n in enumerate(nums):
			if i == 0:
				continue
			pr[i] = max(n, n*pr[i-1], n*nr[i-1])
			nr[i] = min(n, n*pr[i-1], n*nr[i-1])
		print(max(pr))
except Exception as e:
	# print(e)
	pass