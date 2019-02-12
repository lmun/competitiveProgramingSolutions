while True:
	def fabin(i, j):
		return bins[i]-nums[3*j+i]
	try:
		# B G C
		nums = [int(x) for x in input().split()]
		bins = [0]*3
		for i in range(3):
			bins[0] += nums[3*i]
			bins[1] += nums[3*i+1]
			bins[2] += nums[3*i+2]
		res = 10**9
		rewo = ''
		tires = fabin(0,0)
		if fabin(0,0) + fabin(1, 2) + fabin(2,1) < res:
			res = fabin(0,0) + fabin(1, 2) + fabin(2,1)
			rewo = 'BCG'
		if fabin(0,0) + fabin(1, 1) + fabin(2,2) < res:
			res = fabin(0,0) + fabin(1, 1) + fabin(2,2)
			rewo = 'BGC'
		if fabin(2,0) + fabin(0, 1) + fabin(1,2) < res:
			res = fabin(2,0) + fabin(0, 1) + fabin(1,2)
			rewo = 'CBG'
		if fabin(2,0) + fabin(1, 1) + fabin(0,2) < res:
			res = fabin(2,0) + fabin(1, 1) + fabin(0,2)
			rewo = 'CGB'
		if fabin(1,0) + fabin(0, 1) + fabin(2,2) < res:
			res = fabin(1,0) + fabin(0, 1) + fabin(2,2)
			rewo = 'GBC'
		if fabin(1,0) + fabin(2, 1) + fabin(0,2) < res:
			res = fabin(1,0) + fabin(2, 1) + fabin(0,2)
			rewo = 'GCB'
		print(rewo, res)
	except Exception as e:
		#print(e)
		break
