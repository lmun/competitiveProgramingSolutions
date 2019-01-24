while True:
	try:
		x, y = map(int, input().split())
		if x == 0 and y == 0:
			break
		n = 1
		while n*n < y:
			n += 2
		off = (x-n)//2
		olu = 1000
		ine = 1000
		if y > n*n-n:
			olu = n
			ine = n - (n*n-y)
		elif y > n*n-n-n+1:
			ine = 1
			olu = y - (n*n-n-n+1)
		elif y > n*n-n-n-n+2:
			olu = 1
			ine = n*n-n-n+3-y
		else:
			ine = n
			olu = n*n-n-n-n+4-y
		#print(ine, olu, off)
		#print(ine+off,olu+off)
		print("Line = {}, column = {}.".format(ine+off,olu+off))
	except Exception as e:
		break
