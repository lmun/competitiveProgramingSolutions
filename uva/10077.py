while True:
	try:
		a, b = map(int, input().split())
		if a == 1 and b == 1:
			break
		hn, hd, ln, ld = 1, 0, 0, 1
		while True:
			mn, md = hn + ln, hd + ld
			if mn == a and md == b:
				break
			elif mn*b < a*md:
				ln, ld = mn, md
				print('R', end='')
			else:
				hn, hd = mn, md
				print('L', end='')
		print()
	except Exception as e:
		print(e)
		break