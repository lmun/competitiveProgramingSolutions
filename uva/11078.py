for t in range(int(input())):
	try:
		madi = -500000
		mae = -500000
		for i in range(int(input())):
			e = int(input())
			if i > 0:
				madi = max(mae - e, madi)
			mae = max(mae, e)
			#print(i, mae)
		print(madi)
	except Exception as e:
		#print(e)
		break
