while True:
	try:
		ns = list(map(int, input().split()))
		n = ns[0]
		if n == 0:
			break
		nums = ns[1:]
		while len(nums) < n:
			nums.extend(map(int, input().split()))
		res = nums[0]
		act = 0
		for nu in nums:
			act += nu
			if act > res:
				res = act
			if act < 0:
				act = 0
		if res > 0:
			print("The maximum winning streak is {}.".format(res))
		else:
			print("Losing streak.")
	except Exception as e:
		continue
