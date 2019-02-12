while True:
	try:
		def isquirk(n):
			ab = n%mo + n//mo
			return ab*ab==n
		n = int(input())
		mo = 10**(n//2)
		for i in range(2*mo):
			if i*i < 10**n and isquirk(i*i):
				print('{{:0>{}}}'.format(n).format(i*i))
	except Exception as e:
		#print(e)
		break
