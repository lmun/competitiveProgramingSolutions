t = 0
while True:
	try:
		t += 1
		nums = [int(input()) for _ in range(int(input()))]
		quer = [int(input()) for _ in range(int(input()))]
		nums.sort()
		print("Case {}:".format(t))
		for q in quer:
			lo = 0
			hi = len(nums)-1
			res = 0
			mdifi = 10**9
			while hi > lo:
				su = nums[lo]+nums[hi]
				difi = abs(q-su)
				if difi < mdifi:
					mdifi = difi
					res = su
				if su > q:
					hi -= 1
				else:
					lo += 1
			print("Closest sum to {} is {}.".format(q, res))
	except Exception as e:
		#print(e)
		break
