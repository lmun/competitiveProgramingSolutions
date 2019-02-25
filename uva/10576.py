while True:
	try:
		x, y = map(int, input().split())
		n = 1<<5
		nu = n-1
		val = [0]*n
		for i in range(1<<5):
			a = i
			for j in range(5):
				if 1<<j & i:
					val[i] += x
				else:
					val[i] -= y
		maxi = -1
		meses = 12
		for pp in range(1<<meses):
			t = pp
			for i in range(meses-4):
				if val[t & nu] >= 0:
					break
				t >>= 1
			else:
				t = pp
				tot = val[t & nu]
				t >>= 5
				tot += val[t & nu]
				t >>= 5
				for _ in range(2):
					if t & 1:
						tot += x
					else:
						tot -= y
					t >>= 1
				maxi = max(maxi, tot)
		print(maxi if maxi >0 else "Deficit")
	except Exception as e:
		break
